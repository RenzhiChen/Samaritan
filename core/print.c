/*
 * print.c:
 *  This file contains the functions to print the population and the performance metrics.
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

#include "../header/print.h"

/* Output the objective values to file */
void print_variable (char *file_name, void * ptr)
{
    int i, j;

    FILE *fpt;
    fpt = fopen (file_name,"w");

    population_real *pop = (population_real*)ptr;
    for (i = 0; i < popsize; i++)
    {
        for (j = 0; j < number_variable; j++)
            fprintf (fpt, "%lf\t", pop->ind[i].xreal[j]);
        fprintf (fpt, "\n");
    }
    fclose (fpt);

    return;
}

/* Output the objective values to file */
void print_objective (char *file_name, void * ptr)
{
    int i, j;

    FILE *fpt;
    fpt = fopen (file_name, "w");

    population_real *pop = (population_real*)ptr;
    for (i = 0; i < popsize; i++)
    {
        for (j = 0; j < number_objective; j++)
            fprintf (fpt, "%lf\t", pop->ind[i].obj[j]);
        fprintf (fpt, "\n");
    }
    fclose (fpt);

    return;
}

/* Print the current evolution progress */
void print_progress (int generation)
{
    if (generation * 100 / max_generations != (generation - 1) * 100 / max_generations)
    {
        printf ("\rProgress %d%%", generation * 100 / max_generations);
        fflush (stdout);
    }
    if (generation == max_generations)
        printf ("\nRun ended\n");

    return;
}

void print_information (int level, int n, ...)
{
    char symbol[4][3] = {"EE", "II", "DD", "dd"};

    int i;
    char * info = NULL;

    va_list vl;
    va_start (vl, n);
    if (DEBUG >= level)
    {
        printf ("%s::", symbol[level]);
        for(i = 0; i < n; i++)
        {
            info = va_arg (vl, char*);
            printf ("%s", info);
        }
        printf ("\n");

    }
    va_end (vl);

    return;
}
