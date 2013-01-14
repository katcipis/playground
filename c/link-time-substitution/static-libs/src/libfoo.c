/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * lib.c
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

#include "libfoo.h"


gint libfoo_a (void)
{
    g_print("libfoo_a: real\n");
    return 777;
}

gboolean libfoo_b (void)
{
    g_print("libfoo_b: real\n");
    return TRUE;
}

void libfoo_c (gdouble a)
{
    g_print("libfoo_c: real\n");
}

