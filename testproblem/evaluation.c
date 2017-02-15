/*
 * evaluation.c:
 *  This file contains the functions to perform function evaluations.
 *
 * Authors:
 *  Renzhi Chen <rxc332@cs.bham.ac.uk>
 *  Ke Li <k.li@exeter.ac.uk>
 *
 * Copyright (c) 2017 Renzhi Chen, Ke Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../header/problems.h"
#include "../header/global.h"

void evaluate_population (population_real* pop)
{
    int i;

    for (i = 0; i < popsize; i++)
        evaluate_individual (&(pop->ind[i]));

    return;
}

void evaluate_individual (individual_real* ind)
{
    if (problem_index == 1)
    {
        dtlz1 (ind->xreal, ind->obj);
    }
    else if (problem_index == 2)
    {
       zdt1 (ind->xreal, ind->obj);
    }

    return;
}