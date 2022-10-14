// Portions Copyright (c) Meta Platforms, Inc. and affiliates.
// Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

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

std::ostream& operator<<(std::ostream& os, const Entity& entity) {
  os << "EntityGroupId: " << entity.m_entityGroupId;
  os << " EntityId: " << entity.m_entityId;
  return os;
}
