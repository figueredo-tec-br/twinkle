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

#include "definitions.h"
#include "hdr_require.h"

t_hdr_require::t_hdr_require() : t_header("Require") {};

void t_hdr_require::add_feature(const string &f) {
	populated = true;
	if (!contains(f)) {
		features.push_back(f);
	}
}

void t_hdr_require::add_features(const list<string> &l) {
	if (l.empty()) return;
	
	for (list<string>::const_iterator i = l.begin(); i != l.end(); i++)
	{
		add_feature(*i);
	}
	populated = true;
}

void t_hdr_require::del_feature(const string &f) {
	features.remove(f);
}

bool t_hdr_require::contains(const string &f) const {
	if (!populated) return false;

	for (list<string>::const_iterator i = features.begin();
	     i != features.end(); i++)
	{
		if (*i == f) return true;
	}

	return false;
}

string t_hdr_require::encode_value(void) const {
	string s;

	if (!populated) return s;

	for (list<string>::const_iterator i = features.begin();
	     i != features.end(); i++)
	{
		if (i != features.begin()) s += ", ";
		s += *i;
	}

	return s;
}

void t_hdr_require::unpopulate(void) {
	populated = false;
	features.clear();
}
