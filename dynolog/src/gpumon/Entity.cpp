/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "dynolog/src/gpumon/Entity.h"

Entity::Entity(const dcgmGroupEntityPair_t& entity)
    : Entity{entity.entityGroupId, entity.entityId} {}

Entity::Entity(
    dcgm_field_entity_group_t entityGroupId,
    dcgm_field_eid_t entityId)
    : m_entityGroupId{entityGroupId}, m_entityId{entityId} {}

bool Entity::operator<(const Entity& other) const {
  if (m_entityGroupId < other.m_entityGroupId) {
    return true;
  }

  if (m_entityGroupId > other.m_entityGroupId) {
    return false;
  }

  return m_entityId < other.m_entityId;
}

bool Entity::operator==(const Entity& other) const {
  return m_entityGroupId == other.m_entityGroupId &&
      m_entityId == other.m_entityId;
}

int getLatestDcgmValueCB(
    dcgm_field_entity_group_t entityGroupId,
    dcgm_field_eid_t entityId,
    dcgmFieldValue_v1* values,
    int numValues,
    void* userData) {
  if (userData == nullptr) {
    return DCGM_ST_BADPARAM;
  }

  auto* data = static_cast<cbData*>(userData);

  /**
   * If there's no data yet, status of the first record will be
   * DCGM_ST_NO_DATA
   */
  if (values[0].status == DCGM_ST_NO_DATA) {
    return DCGM_ST_OK;
  } else if (values[0].status != DCGM_ST_OK) {
    return DCGM_ST_OK;
  }

  dcgmGroupEntityPair_t entity;

  entity.entityGroupId = entityGroupId;
  entity.entityId = entityId;

  data->m_values[entity].insert(
      data->m_values[entity].end(), values, values + numValues);

  return DCGM_ST_OK;
}

std::ostream& operator<<(std::ostream& os, const Entity& entity) {
  os << "EntityGroupId: " << entity.m_entityGroupId;
  os << " EntityId: " << entity.m_entityId;
  return os;
}
