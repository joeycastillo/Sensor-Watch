#include <hpl_slcd_config.h>

/**
 * character segments position index
 *
 * For a 14-segments character, each segment has an unique position index.
 * The segment layout and position index value is shown as below.
 * The symbol '-', '|', '/', '\' represent the SLCD character segment, and the
 * number represent each segment's position index, which equals to macro
 * SEG14_0 to SEG14_7.
 * The character lookup mapping table use those position index
 * (SEG14_0..SEG14_14) to compose some visible arabic numerals, letters or some
 * specific ASCII.
 * For example char '1' can be represented by use position index 1,2.
 * (SEG7_1 | SEG7_2).
 * More predefined character lookup can be found at below "14-segment character
 * lookup mapping table"
 *
 *         -0
 * |5  \6  |7  /8  |1
 *     -9      -10
 * |4  /11 |12 \13 |2
 *         -3
 */

/**
 * Character segment position remapping setting
 *
 * An SLCD screen typically use several hardware segments to display a
 * character(for example from COM3/SEG0 to COM4/SEG7).
 * The lowest COM and SEG index is 0 (COM3/SEG0 index is 0).
 * The "hardware character segments index" maybe different with the "character
 * segments position index". The remapping setting allow application to adjust
 * those sequence.
 *
 */
#define SEG14_0 (0x1 << CONF_SLCD_CM_14SEGS_0_SETTING)
#define SEG14_1 (0x1 << CONF_SLCD_CM_14SEGS_1_SETTING)
#define SEG14_2 (0x1 << CONF_SLCD_CM_14SEGS_2_SETTING)
#define SEG14_3 (0x1 << CONF_SLCD_CM_14SEGS_3_SETTING)
#define SEG14_4 (0x1 << CONF_SLCD_CM_14SEGS_4_SETTING)
#define SEG14_5 (0x1 << CONF_SLCD_CM_14SEGS_5_SETTING)
#define SEG14_6 (0x1 << CONF_SLCD_CM_14SEGS_6_SETTING)
#define SEG14_7 (0x1 << CONF_SLCD_CM_14SEGS_7_SETTING)
#define SEG14_8 (0x1 << CONF_SLCD_CM_14SEGS_8_SETTING)
#define SEG14_9 (0x1 << CONF_SLCD_CM_14SEGS_9_SETTING)
#define SEG14_10 (0x1 << CONF_SLCD_CM_14SEGS_10_SETTING)
#define SEG14_11 (0x1 << CONF_SLCD_CM_14SEGS_11_SETTING)
#define SEG14_12 (0x1 << CONF_SLCD_CM_14SEGS_12_SETTING)
#define SEG14_13 (0x1 << CONF_SLCD_CM_14SEGS_13_SETTING)

/**
 * 17-segments character mask value
 */
#define SEG14_MASK                                                                                                     \
	(0xFFFFFF                                                                                                          \
	 & ~(SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_6 | SEG14_7 | SEG14_8 | SEG14_9 | SEG14_10  \
	     | SEG14_11 | SEG14_12 | SEG14_13))

/**
 * 14-segment character lookup mapping table
 * struct slcd_char_mapping;
 */
#define SLCD_SEG14_LUT                                                                                                 \
	{                                                                                                                  \
		{'0', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_8 | SEG14_11},                         \
		    {'1', SEG14_1 | SEG14_2}, {'2', SEG14_0 | SEG14_1 | SEG14_3 | SEG14_4 | SEG14_9 | SEG14_10},               \
		    {'3', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_9 | SEG14_10},                                         \
		    {'4', SEG14_1 | SEG14_2 | SEG14_5 | SEG14_9 | SEG14_10},                                                   \
		    {'5', SEG14_0 | SEG14_2 | SEG14_3 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'6', SEG14_0 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                               \
		    {'7', SEG14_0 | SEG14_1 | SEG14_2},                                                                        \
		    {'8', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                     \
		    {'9', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_5 | SEG14_9 | SEG14_10},                               \
		    {'a', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                               \
		    {'b', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_7 | SEG14_10 | SEG14_12},                              \
		    {'c', SEG14_0 | SEG14_3 | SEG14_4 | SEG14_5},                                                              \
		    {'d', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_7 | SEG14_12},                                         \
		    {'e', SEG14_0 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'f', SEG14_0 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                                                   \
		    {'g', SEG14_0 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_10},                                         \
		    {'h', SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'i', SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'j', SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4}, {'k', SEG14_4 | SEG14_5 | SEG14_8 | SEG14_9 | SEG14_13},     \
		    {'l', SEG14_3 | SEG14_4 | SEG14_5}, {'m', SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_6 | SEG14_8},      \
		    {'n', SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_6 | SEG14_13},                                         \
		    {'o', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5},                                          \
		    {'p', SEG14_0 | SEG14_1 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'q', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5 | SEG14_13},                               \
		    {'r', SEG14_0 | SEG14_1 | SEG14_4 | SEG14_5 | SEG14_9 | SEG14_10 | SEG14_13},                              \
		    {'s', SEG14_0 | SEG14_3 | SEG14_5 | SEG14_9 | SEG14_13}, {'t', SEG14_0 | SEG14_7 | SEG14_12},              \
		    {'u', SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_5}, {'v', SEG14_4 | SEG14_5 | SEG14_8 | SEG14_11},     \
		    {'w', SEG14_1 | SEG14_2 | SEG14_4 | SEG14_5 | SEG14_11 | SEG14_13},                                        \
		    {'x', SEG14_6 | SEG14_8 | SEG14_11 | SEG14_13},                                                            \
		    {'y', SEG14_1 | SEG14_2 | SEG14_3 | SEG14_5 | SEG14_9 | SEG14_10},                                         \
		    {'z', SEG14_0 | SEG14_3 | SEG14_8 | SEG14_11}, {'-', SEG14_9 | SEG14_10},                                  \
		    {'+', SEG14_7 | SEG14_9 | SEG14_10 | SEG14_12}, {'/', SEG14_8 | SEG14_11},                                 \
		    {'=', SEG14_3 | SEG14_9 | SEG14_10},                                                                       \
		    {'#', SEG14_1 | SEG14_2 | SEG14_3 | SEG14_7 | SEG14_9 | SEG14_10 | SEG14_12},                              \
		    {'*', SEG14_6 | SEG14_8 | SEG14_11 | SEG14_13}, {'\'', SEG14_13}, {')', SEG14_6 | SEG14_11},               \
		    {'(', SEG14_8 | SEG14_13}, {'@', SEG14_0 | SEG14_1 | SEG14_2 | SEG14_3 | SEG14_4 | SEG14_9 | SEG14_13},    \
		    {'$', SEG14_0 | SEG14_2 | SEG14_3 | SEG14_5 | SEG14_7 | SEG14_9 | SEG14_10 | SEG14_12},                    \
		    {'%', SEG14_2 | SEG14_5 | SEG14_8 | SEG14_11}, {'\\', SEG14_6 | SEG14_13}, {'_', SEG14_3}, {0, 0},         \
	}
