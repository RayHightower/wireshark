/* packet-gsm_sms.h
 *
 * $Id$
 *
 * Copyright 2004, Michael Lum <mlum [AT] telostech.com>,
 * In association with Telos Technology Inc.
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* Convert a 7-bit GSM SMS packed string into an unpacked string.
 *
 * @param offset Bit offset of the start of the string.
 * @param in_length Length of the packed string in bytes.
 * @param out_length Length of the output string in bytes.
 * @param input The string to unpack
 * @param output The buffer for the output string. This buffer must
 *               be pre-allocated and be at least out_length characters
 *               long, or out_length + 1 if you're planning on adding a
 *               terminating '\0'.
 * @return The number of unpacked characters.
 */

extern int gsm_sms_char_7bit_unpack(unsigned int offset, unsigned int in_length, unsigned int out_length,
		     const guint8 *input, unsigned char *output);

/* Convert an unpacked SMS string to UTF-8.
 *
 * @param src The string to convert.
 * @param len Length of the string to convert, in bytes.
 * @return An ep_allocated UTF-8 string.
 */

extern gchar *gsm_sms_chars_to_utf8(const unsigned char* src, int len);

enum character_set {
    OTHER,
    GSM_7BITS,
    ASCII_7BITS
};

void dis_field_udh(tvbuff_t *tvb, proto_tree *tree, guint32 *offset, guint32 *length,
                   guint8 *udl, enum character_set cset, guint8 *fill_bits);

/* Data structure that can be optionally given to gsm_sms dissector */
typedef struct _gsm_sms_data_t {
    gboolean stk_packing_required;
} gsm_sms_data_t;
