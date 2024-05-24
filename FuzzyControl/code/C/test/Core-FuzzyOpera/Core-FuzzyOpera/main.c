#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "fc.h"

static bool print_number(fuzzy_number fn, void* data)
{
	UNUSED(data);
	printf("%0.2f\t", fn);

	return true;
}

int main()
{
	srand(time(NULL));

	// fuzzy matrix
	printf("\r\n");
	printf("================================================================\r\n");
	printf("    fuzzy matrix\r\n");
	printf("================================================================\r\n");
	{
		struct fuzzy_matrix mat;
		fuzzy_matrix_init(&mat);
		fuzzy_matrix_create(&mat, 3, 4);

		printf("\r\n");
		printf("--------------------------------\r\n");
		printf("    trav\r\n");
		printf("--------------------------------\r\n");
		for (size_t r = 0; r < mat.row; r++)
		{
			for (size_t c = 0; c < mat.col; c++)
			{
				size_t base = r * mat.col + c;
				//mat.mat[r][c] = (float)(rand() % (100 * (base ? base : 1))) / 100;
				mat.mat[r][c] = base;
			}
		}
		fuzzy_matrix_trav(&mat, nullptr, print_number);

		printf("\r\n");
		printf("--------------------------------\r\n");
		printf("    trans\r\n");
		printf("--------------------------------\r\n");
		struct fuzzy_matrix matT;
		fuzzy_matrix_init(&matT);

		fuzzy_opera_trans(&mat, &matT);
		fuzzy_matrix_print(&mat, "mat");
		fuzzy_matrix_print(&matT, "matT");

		fuzzy_matrix_delete(&matT);
		fuzzy_matrix_delete(&mat);
	}

	{
		printf("\r\n");
		printf("--------------------------------\r\n");
		printf("    dir_pro and copy\r\n");
		printf("--------------------------------\r\n");
		struct fuzzy_matrix mat1;
		struct fuzzy_matrix mat2;
		struct fuzzy_matrix result;
		fuzzy_matrix_init(&mat1);
		fuzzy_matrix_init(&mat2);
		fuzzy_matrix_init(&result);

		fuzzy_matrix_create(&mat1, 1, 3);
		fuzzy_matrix_create(&mat2, 1, 2);
		mat1.mat[0][0] = 0.0058; mat1.mat[0][1] = 0.9633; mat1.mat[0][2] = 0.3978;
		mat2.mat[0][0] = 0.8999; mat2.mat[0][1] = 0.5896;

		printf("\r\n\n1st dir_pro\r\n");
		fuzzy_opera_dir_pro(&mat1, &mat2, &result);
		fuzzy_matrix_print(&mat1, "mat1");
		fuzzy_matrix_print(&mat2, "mat2");
		fuzzy_matrix_print(&result, "result");

		printf("\r\n\n2nd dir_pro\r\n");
		fuzzy_matrix_copy(&mat1, &result);
		fuzzy_opera_dir_pro(&mat1, &mat2, &result);
		fuzzy_matrix_print(&mat1, "mat1");
		fuzzy_matrix_print(&mat2, "mat2");
		fuzzy_matrix_print(&result, "result");

		fuzzy_matrix_delete(&mat1);
		fuzzy_matrix_delete(&mat2);
		fuzzy_matrix_delete(&result);
	}

	{
		printf("\r\n");
		printf("--------------------------------\r\n");
		printf("    reshape clear\r\n");
		printf("--------------------------------\r\n");

		struct fuzzy_matrix mat;
		fuzzy_matrix_init(&mat);
		fuzzy_matrix_create(&mat, 3, 4);
		for (fuzzy_size r = 0; r < mat.row; r++)
		{
			for (fuzzy_size c = 0; c < mat.col; c++)
			{
				mat.mat[r][c] = r * mat.col + c;
			}
		}

		fuzzy_matrix_print(&mat, "ori mat");

		fuzzy_matrix_reshape(&mat, 5, 5);
		fuzzy_matrix_print(&mat, "reshape mat");
		fuzzy_matrix_reshape(&mat, 9, 5);
		fuzzy_matrix_print(&mat, "reshape mat again");
		fuzzy_matrix_reshape(&mat, 5, 5);
		fuzzy_matrix_print(&mat, "reshape mat again 2");
		fuzzy_matrix_clear(&mat);
		fuzzy_matrix_print(&mat, "reshape mat clear");
		for (fuzzy_size r = 0; r < mat.row; r++)
		{
			for (fuzzy_size c = 0; c < mat.col; c++)
			{
				mat.mat[r][c] = r * mat.col + c;
			}
		}
		fuzzy_matrix_print(&mat, "then");
		fuzzy_matrix_reshape_s(&mat, 6, 6);
		fuzzy_matrix_print(&mat, "reshape_s mat");
	}

	return 0;
}
