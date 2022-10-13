add_library(dynolog_dcgm_lib
    DcgmApiStub.cpp DcgmApiStub.h
    DcgmGroupInfo.cpp DcgmGroupInfo.h
    Entity.cpp Entity.h
    dcgm_fields.h
    dcgm_agent.h
    dcgm_errors.h
    dcgm_structs.h
    dcgm_api_export.h
)
target_include_directories(dynolog_dcgm_lib
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(dynolog_dcgm_lib PUBLIC gflags::gflags)
target_link_libraries(dynolog_dcgm_lib PUBLIC glog::glog)
target_link_libraries(dynolog_dcgm_lib PUBLIC nlohmann_json::nlohmann_json)
