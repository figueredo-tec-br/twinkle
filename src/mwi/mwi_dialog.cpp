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

#include "mwi_dialog.h"

#include "mwi_subscription.h"
#include "phone_user.h"
#include "audits/memman.h"

t_mwi_dialog::t_mwi_dialog(t_phone_user *_phone_user) :
	t_subscription_dialog(_phone_user)
{
	subscription = new t_mwi_subscription(this, &(phone_user->mwi));
	MEMMAN_NEW(subscription);
}

t_mwi_dialog *t_mwi_dialog::copy(void) {
	// Copy is not needed.
	assert(false);
	return NULL;
}
