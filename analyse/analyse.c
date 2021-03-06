/*
 * analyse.c:
 *  This file contains the functions to record the results, including the population and metric values for analysis.
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

# include "../header/analyse.h"
# include "../header/utility.h"

void track_evolution (void *ptr, int id)
{
    int i, j;
    int read_ptr;

    char name[20];
    char id_char[10];

    char output_dir_level1[200];    // upper level directory
    char output_dir_level2[200];    // lower level directory
    char output_file[200];

    sprintf (id_char, "%d", id);
    // set the output directory
    sprintf (output_dir_level1, "./%s_%d_%d/%s/",
             problem_name,
             number_variable,
             number_objective,
             algorithm_name
    );
    sprintf (output_dir_level2, "./%s_%d_%d/%s/%d/",
             problem_name,
             number_variable,
             number_objective,
             algorithm_name,
             run_index
    );
    _mkdir (output_dir_level2);

    // first time output, init the parameter and output var and fun
    if (id == 1)
    {
        // set analyse list
        for (i = 0; i < 100; i++)
            analyse_list[i] = 0;

        read_ptr = 0;
        while (1)

        {
            int name_c = 0;
            while (analyse_stream[read_ptr] != ' '
                   && analyse_stream[read_ptr] != '\t'
                   && analyse_stream[read_ptr] != '\n'
                   && analyse_stream[read_ptr] != 0)
            {
                name[name_c] = analyse_stream[read_ptr];
                name_c++;
                read_ptr++;
            }
            if (analyse_stream[read_ptr] == 0)
                name[name_c] = 0;
            name[name_c] = 0;

            if (!strcmp(name, "VAR"))
                analyse_list[VAR] = 1;
            else if (!strcmp(name, "FUN"))
                analyse_list[FUN] = 1;
            else if (!strcmp(name, "IGD"))
                analyse_list[IGD] = 1;

            if (analyse_stream[read_ptr] == 0)
                break;
            read_ptr++;
        }
    }

    if (runtime_output == 1 && (id % output_interval == 0 || id == 1 || id == max_generations))
    {
        if (analyse_list[VAR])
        {
            sprintf (output_file, "%smedium_VAR_%s.out", output_dir_level2, id_char);
            print_variable (output_file, ptr);
        }
        if (analyse_list[FUN])
        {
            sprintf (output_file, "%smedium_FUN_%s.out", output_dir_level2, id_char);
            print_objective (output_file, ptr);
        }
        if (analyse_list[IGD])
        {
            record_igd (ptr, id);
        }
    }

    if (id == max_generations)
    {
        if (analyse_list[VAR])
        {
            sprintf (output_file, "%sVAR%d.out", output_dir_level1, run_index);
            print_variable (output_file, ptr);
        }
        if (analyse_list[FUN])
        {
            sprintf (output_file, "%sFUN%d.out", output_dir_level1, run_index);
            print_objective (output_file, ptr);
        }
        if (analyse_list[IGD])
        {
            if (runtime_output == 1)
            {
                sprintf (output_file, "%sIGD_%d.txt", output_dir_level2, run_index);
                print_igd (output_file);
            }
        }
    }
}

void analyse_all ()
{
    char output_dir_level1[200];
    char output_file[200];

    sprintf (output_dir_level1,"./%s_%d_%d/%s/",
             problem_name,
             number_variable,
             number_objective,
             algorithm_name
    );
    if (analyse_list[IGD])
    {
        sprintf (output_file, "%sIGD.txt", output_dir_level1);
        print_global_igd (output_file);
    }

    return;
}
