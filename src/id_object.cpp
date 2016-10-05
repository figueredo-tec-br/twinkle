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

#include "id_object.h"

// Initialization of static members
t_mutex t_id_object::mtx_next_id;
t_object_id t_id_object::next_id = 1;

t_id_object::t_id_object() {
	mtx_next_id.lock();
	id = next_id++;
	if (next_id == 65535) next_id = 1;
	mtx_next_id.unlock();
}

t_object_id t_id_object::get_object_id() {
	return id;
}

void t_id_object::generate_new_id() {
	mtx_next_id.lock();
	id = next_id++;
	if (next_id == 65535) next_id = 1;
	mtx_next_id.unlock();
}
