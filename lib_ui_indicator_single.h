#ifndef LIB_UI_INDICATOR_SINGLE_H
#define LIB_UI_INDICATOR_SINGLE_H

#include <stdbool.h>

/* =====================================================================================================================
 *                                                                                                   DEFAULT DEFINITIONS
 * =====================================================================================================================
 */
/* define LIB_UI_INDICATOR_SINGLE_PULSE_SHORT in deployment header to change the default short pulse length
 */
#ifndef LIB_UI_INDICATOR_SINGLE_PULSE_SHORT
#define LIB_UI_INDICATOR_SINGLE_PULSE_SHORT 100
#warning "LIB_UI_INDICATOR_SINGLE: DEFAULT value used for LIB_UI_INDICATOR_SINGLE_PULSE_SHORT"
#endif /* LIB_UI_INDICATOR_SINGLE_PULSE_SHORT */

/* define LIB_UI_INDICATOR_SINGLE_PULSE_LONG in deployment header to change the default long pulse length
 */
#ifndef LIB_UI_INDICATOR_SINGLE_PULSE_LONG
#define LIB_UI_INDICATOR_SINGLE_PULSE_LONG 300
#warning "LIB_UI_INDICATOR_SINGLE: DEFAULT value used for LIB_UI_INDICATOR_SINGLE_PULSE_LONG"
#endif /* LIB_UI_INDICATOR_SINGLE_PULSE_LONG */

/* =====================================================================================================================
 *                                                                                           Enumerations and Structures
 * =====================================================================================================================
 */

enum e_lib_ui_indicator_single_sequence
{
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_OFF = 0,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_ON,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_PULSE,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_IDLE,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_ERROR,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_FATAL,
    enum_LIB_UI_INDICATOR_SINGLE_SEQUENCE_LIMIT
};

enum e_lib_ui_indicator_single_major
{
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_ZERO = 0,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_ONE,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_TWO,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_THREE,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_FOUR,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_FIVE,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_SIX,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_SEVEN,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_EIGHT,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_NINE,
    enum_LIB_UI_INDICATOR_SINGLE_MAJOR_LIMIT
};

enum e_lib_ui_indicator_single_minor
{
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_ZERO = 0,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_ONE,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_TWO,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_THREE,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_FOUR,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_FIVE,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_SIX,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_SEVEN,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_EIGHT,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_NINE,
    enum_LIB_UI_INDICATOR_SINGLE_MINOR_LIMIT
};

enum e_lib_ui_indicator_single_patch
{
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_ZERO = 0,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_ONE,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_TWO,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_THREE,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_FOUR,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_FIVE,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_SIX,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_SEVEN,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_EIGHT,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_NINE,
    enum_LIB_UI_INDICATOR_SINGLE_PATCH_LIMIT
};

struct s_lib_ui_indicator_single
{
    bool current_state;
    enum e_lib_ui_indicator_single_seqeuence sequence;
    uint8_t sequence_step;
    enum e_lib_ui_indicator_single_major code_major;
    enum e_lib_ui_indicator_single_minor code_minor;
    enum e_lib_ui_indicator_single_patch code_patch;
};

bool
lib_ui_indicator_single_init(
    struct s_lib_ui_indicator_single* new_status,
    );

void
lib_ui_indicator_single_set(
    struct s_lib_ui_indicator_single* status,
    enum e_lib_ui_indicator_single_sequence new_sequence,
    enum e_lib_ui_indicator_single_major code_major,
    enum e_lib_ui_indicator_single_minor code_minor,
    enum e_lib_ui_indicator_single_patch code_patch
    );

void
lib_ui_indicator_single_cycle(
    struct s_lib_ui_indicator_single* status,
    );

#ifdef DEPLOYMENT_OPTION_RUN_UNIT_TESTS
bool
run_unit_tests__lib_ui_indicator_single(
    void
    );
#endif /* DEPLOYMENT_OPTION_RUN_UNIT_TESTS */

#endif /* LIB_UI_INDICATOR_SINGLE_H */
