/*
 * reproduction.h:
 *  This is the header file for the reproduction operation
 *
 * Authors:
 *  Renzhi Chen <rxc332@cs.bham.ac.uk>
 *  Ke Li <k.li@exeter.ac.uk>
 *
 * Institution:
 *  Computational Optimization and Data Analytics (CODA) Group @ University of Exeter
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
# ifndef Samaritan_REPRODUCTION_H
# define Samaritan_REPRODUCTION_H

# include "../header/global.h"

// mating selection
individual_real* tournament (individual_real *ind1, individual_real *ind2);

// crossover
void crossover_real (population_real *parent_pop, population_real* offspring_pop);
void sbx_crossover (individual_real *parent1, individual_real *parent2, individual_real *child1, individual_real *child2);

// mutation
void polymut_ind (individual_real *ind);
void mutation_ind (individual_real *ind);
void mutation_real (population_real *pop);


# endif // Samaritan_REPRODUCTION_H
