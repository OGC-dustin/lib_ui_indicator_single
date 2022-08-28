/*
 * OGC Engineering
 * Library UI Indicator Single
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef INCLUDE_OS_NRTPS_LIBRARY
#include "lib_os_nrtps.h"
#endif

#ifdef INCLUDE_OS_FREERTOS
#include "lib_os_freertos.h"
#endif

#include "lib_ui_indicator_single.h"
#include "hal.h"

bool
lib_ui_indicator_single_init(
    struct s_lib_ui_indicator_single* new_status,
    )
{
    if ( NULL != new_status )
    {
        new_status->current_state = false;
        new_status->sequence = enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_OFF;
        new_status->sequence_step = 0U;
        new_status->code_major = enum_LIB_UI_INDICATOR_SINGLE_MAJOR_LIMIT;
        new_status->code_minor = enum_LIB_UI_INDICATOR_SINGLE_MINOR_LIMIT;
        new_status->code_patch = enum_LIB_UI_INDICATOR_SINGLE_PATCH_LIMIT;
    }

#ifdef INCLUDE_OS_NRTPS_LIBRARY
    enum e_lib_os_nrtps_status return_status;
    return_status = lib_os_nrtps_set( 1000U, lib_ui_indicator_single_cycle, new_status );
    if ( enum_LIB_OS_NRTPS_STATUS__FAILURE != return_status )
    {
        return ( true );
    }
    else
    {
        return ( false );
    }
#endif

#ifdef INCLUDE_OS_FREERTOS
#endif

}

void
lib_ui_indicator_single_set(
    struct s_lib_ui_indicator_single* status,
    enum e_lib_ui_indicator_single_sequence new_sequence,
    enum e_lib_ui_indicator_single_major code_major,
    enum e_lib_ui_indicator_single_minor code_minor,
    enum e_lib_ui_indicator_single_patch code_patch
    )
{
    if ( ( NULL != status )
         && ( enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_LIMIT > new_sequence )
         && ( enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_OFF <= new_sequence )
         && ( enum_LIB_UI_INDICATOR_SINGLE_MAJOR_ZERO < code_major )
         && ( enum_LIB_UI_INDICATOR_SINGLE_MAJOR_LIMIT > code_major )
         && ( enum_LIB_UI_INDICATOR_SINGLE_MINOR_ZERO < code_minor )
         && ( enum_LIB_UI_INDICATOR_SINGLE_MINOR_LIMIT > code_minor )
         && ( enum_LIB_UI_INDICATOR_SINGLE_PATCH_ZERO < code_patch )
         && ( enum_LIB_UI_INDICATOR_SINGLE_PATCH_LIMIT > code_patch )
       )
    {
        status->current_state = false;
        status->sequence = enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_OFF;
        status->sequence_step = 0U;
        status->code_major = code_major;
        status->code_minor = code_minor;
        status->code_patch = code_patch;
    }
}

void
lib_ui_indicator_single_cycle(
    struct s_lib_ui_indicator_single* status,
    )
{

}

#ifdef DEPLOYMENT_OPTION_RUN_UNIT_TESTS
#include <stdbool.h>
bool
run_unit_tests__lib_ui_indicator_single(
    void
    );
#endif /* DEPLOYMENT_OPTION_RUN_UNIT_TESTS */
