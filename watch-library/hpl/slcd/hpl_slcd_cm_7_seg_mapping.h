#include <hpl_slcd_config.h>

/**
 * character segments position index
 *
 * For a 7 segments character, each segment has an unique position index.
 * The segment layout and position index value is shown as below.
 * The symbol '-', '|' represent the SLCD character segment, and the
 * number represent each segment's position index, which equals to macro
 * SEG7_0 to SEG7_7.
 * The character lookup mapping table use those position index (SEG7_0..SEG7_7)
 * to compose some visible arabic numerals, letters or some specific ASCII.
 * For example char '0' can be represented by use position index 0,1,2,3,4,5.
 * (SEG7_0 | SEG7_1 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5).
 * More predefined character lookup can be found at below "7-segments character
 * lookup mapping table"
 *   -0
 * |5   |1
 *   -6
 * |4   |2
 *   -3
 */

/**
 * Character segment position remapping setting
 *
 * An SLCD screen typically use several hardware segments to display a
 * character(for example from COM3/SEG0 to COM3/SEG7).
 * The lowest COM and SEG index is 0 (COM3/SEG0 index is 0).
 * The "hardware character segments index" maybe different with the "character
 * segments position index". The remapping setting allow application to adjust
 * those sequence.
 *
 */
#define SEG7_0 (0x1 << CONF_SLCD_CM_7SEGS_0_SETTING)
#define SEG7_1 (0x1 << CONF_SLCD_CM_7SEGS_1_SETTING)
#define SEG7_2 (0x1 << CONF_SLCD_CM_7SEGS_2_SETTING)
#define SEG7_3 (0x1 << CONF_SLCD_CM_7SEGS_3_SETTING)
#define SEG7_4 (0x1 << CONF_SLCD_CM_7SEGS_4_SETTING)
#define SEG7_5 (0x1 << CONF_SLCD_CM_7SEGS_5_SETTING)
#define SEG7_6 (0x1 << CONF_SLCD_CM_7SEGS_6_SETTING)

/**
 * 7-segments character mask value
 */
#define SEG7_MASK (0xFFFFFF & ~(SEG7_0 | SEG7_1 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5 | SEG7_6))

/**
 * 7-segments character lookup mapping table.
 *
 * Array value of slcd_char_mapping struct, application can add or remove
 * item from it.
 */
#define SLCD_SEG7_LUT                                                                                                  \
	{                                                                                                                  \
		{0, 0}, {'0', SEG7_0 | SEG7_1 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5}, {'1', SEG7_1 | SEG7_2},                    \
		    {'2', SEG7_0 | SEG7_1 | SEG7_3 | SEG7_4 | SEG7_6}, {'3', SEG7_0 | SEG7_1 | SEG7_2 | SEG7_3 | SEG7_6},      \
		    {'4', SEG7_1 | SEG7_2 | SEG7_5 | SEG7_6}, {'5', SEG7_0 | SEG7_2 | SEG7_3 | SEG7_5 | SEG7_6},               \
		    {'6', SEG7_0 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5 | SEG7_6}, {'7', SEG7_0 | SEG7_1 | SEG7_2},               \
		    {'8', SEG7_0 | SEG7_1 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5 | SEG7_6},                                       \
		    {'9', SEG7_0 | SEG7_1 | SEG7_2 | SEG7_5 | SEG7_6},                                                         \
		    {'a', SEG7_0 | SEG7_1 | SEG7_2 | SEG7_4 | SEG7_5 | SEG7_6},                                                \
		    {'b', SEG7_2 | SEG7_3 | SEG7_4 | SEG7_5 | SEG7_6}, {'c', SEG7_0 | SEG7_3 | SEG7_4 | SEG7_5},               \
		    {'d', SEG7_1 | SEG7_2 | SEG7_3 | SEG7_4 | SEG7_6}, {'e', SEG7_0 | SEG7_3 | SEG7_4 | SEG7_5 | SEG7_6},      \
		{                                                                                                              \
			'f', SEG7_0 | SEG7_4 | SEG7_5 | SEG7_6                                                                     \
		}                                                                                                              \
	}
