/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "hdr_sip_if_match.h"

t_hdr_sip_if_match::t_hdr_sip_if_match() : t_header("SIP-If-Match") {};

void t_hdr_sip_if_match::set_etag(const string &_etag) {
	populated = true;
	etag = _etag;
}

string t_hdr_sip_if_match::encode_value(void) const {
	if (!populated) return "";
	return etag;
}

void t_hdr_sip_if_match::clear(void) {
	etag.clear();
	populated = false;
}
