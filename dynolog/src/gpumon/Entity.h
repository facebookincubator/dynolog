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
// clang format off

#pragma once

#include <map>
#include <ostream>
#include <vector>
#include "dynolog/src/gpumon/dcgm_fields.h"
#include "dynolog/src/gpumon/dcgm_structs.h"

// A wrapper around dcgmGroupEntityPair_t that allows comparison (for maps).
struct Entity {
  dcgm_field_entity_group_t
      m_entityGroupId; //!< Entity Group ID entity belongs to
  dcgm_field_eid_t m_entityId; //!< Entity ID of the entity

  Entity(const dcgmGroupEntityPair_t&);
  Entity(dcgm_field_entity_group_t, dcgm_field_eid_t);

  bool operator<(const Entity& other) const;
  bool operator==(const Entity& other) const;

  bool isGpu() const {
    return m_entityGroupId == DCGM_FE_GPU;
  }
  bool isGpuInstance() const {
    return m_entityGroupId == DCGM_FE_GPU_I;
  }
  bool isComputeInstance() const {
    return m_entityGroupId == DCGM_FE_GPU_CI;
  }
};

struct cbData {
  std::map<Entity, std::vector<dcgmFieldValue_v1>>& m_values;

  explicit cbData(std::map<Entity, std::vector<dcgmFieldValue_v1>>& values)
      : m_values(values) {}
};

static int getLatestDcgmValueCB(
    dcgm_field_entity_group_t entityGroupId,
    dcgm_field_eid_t entityId,
    dcgmFieldValue_v1* values,
    int numValues,
    void* userData) {
  if (userData == nullptr) {
    return DCGM_ST_BADPARAM;
  }

  cbData* data = (cbData*)userData;

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

std::ostream& operator<<(std::ostream& os, const Entity& entity);
