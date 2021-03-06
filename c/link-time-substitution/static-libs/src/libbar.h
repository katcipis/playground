/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * libfoo.h
 * Copyright (C) 2013 Tiago Katcipis <tiagokatcipis@gmail.com>
 * 
 * libfoobar is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libfoobar is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBBAR_H__
#define __LIBBAR_H__

#include <glib.h>

G_BEGIN_DECLS

gint libbar_a (void);

gboolean libbar_b (void);

void libbar_c (gdouble a);

G_END_DECLS

#endif /* __LIBBAR_H__ */
