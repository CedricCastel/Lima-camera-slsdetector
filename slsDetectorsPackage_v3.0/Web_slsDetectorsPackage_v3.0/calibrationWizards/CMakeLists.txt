
set (SOURCES
    TSlsDetector.cpp
    enCalWizard.cpp
    energyCalibration.cpp
    energyConversion.cpp
    angCalWizard.cpp
    angularConversionStatic.cpp
    angularCalibration.cpp
    enCalDict.cxx
)

set (HEADERS
    TSlsDetector.h
    enCalWizard.h
    enCalLogClass.h
    fileIOStatic.h
    energyCalibration.h
    energyConversion.h
    sls_detector_defs.h
    scanStep.h
    angularConversionStatic.h
    angCalLogClass.h
    angularCalibration.h
    angCalWizard.h
    badChannelCorrections.h
)

include_directories(
    ${ROOT_INCLUDE_DIR}
)

root_generate_dictionary(
    enCalDict
    ${HEADERS}
    LINKDEF enCalLinkDef.h
)
add_custom_target(dictionary
    DEPENDS enCalDict.cxx enCalDict.h
)
add_executable(energyCalibrationWizard
    ${SOURCES}
    ${HEADERS}
    energyCalibrationWizard.cpp
)
set_target_properties(energyCalibrationWizard PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMPILE_DEFINITIONS MYROOT=1
)
target_link_libraries(energyCalibrationWizard
    ${ROOT_GUI_LIBRARIES}
    Minuit
)
add_dependencies(energyCalibrationWizard dictionary)
add_executable(angularCalibrationWizard
    ${SOURCES}
    ${HEADERS}
    angularCalibrationWizard.cpp
)
set_target_properties(angularCalibrationWizard PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMPILE_DEFINITIONS MYROOT=1
)
target_link_libraries(angularCalibrationWizard
    ${ROOT_GUI_LIBRARIES}
    Minuit
)
add_dependencies(angularCalibrationWizard dictionary)
