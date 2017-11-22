/* Unroll inner loop four times */
void ByteMult(unsigned long* a, unsigned long* b, unsigned long*c, long n)
{
	/* Initialize loop index variables */
	long i=0, j=0, k=0;
	/* Initialize sum variables */
	unsigned long sum, sum1, sum2, sum3, sum4;

	/* 
	 * First (outer) loop
	 */
	for (i = 0; i < n; ++i)
	{
		/* Used to access different rows in 1D array implementation */
		long in = i*n;

		/*
		 * Second (middle) loop
		 */
		for (j = 0; j < n; ++j)
		{
			/* Set sum variables to zero for this iteration */
			sum = 0;
			sum1 = 0;
			sum2 = 0;
			sum3 = 0;
			sum4 = 0;

			/* 
			 * Third (inner) loop
			 * Increment the loop by four for this unroll
			 *
			 * Only start at this loop if the matrix size is greater than
			 * or equal to four
			 */
			if (n >= 4)
			{
				for (k = 0; k < n; k+=4)
				{
					/* Group four iterations of the loop into one */
					sum1 = sum1 + a[in+k] * b[k*n+j];
					sum2 = sum2 + a[in+(k+1)] * b[(k+1)*n+j];
					sum3 = sum3 + a[in+(k+2)] * b[(k+2)*n+j];
					sum4 = sum4 + a[in+(k+3)] * b[(k+3)*n+j];
				}
				sum = sum1 + sum2 + sum3 + sum4;
			}

			/*
			 * Handle tail cases
			 *
			 * Just a simple for-loop that does however many iterations
			 * are in the remainder of n and the loop-unroll amount
			 * (In this case, the factor is four)
			 *
			 * The loop will start at n - however many tail cases there are
			 *
			 * If n % k is zero (no tail cases), then the loop will simply
			 * never be run. It'll fail the condition immediately
			 */
			for (k = n - (n % 4); k < n; ++k)
			{
				sum = sum + a[in+k] * b[k*n+j];
			}
			
			/* Set the appropriate value in the matrix to the calculated sum */
			c[in+j] = sum;
		}
	}
}
