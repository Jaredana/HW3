void ByteMult(unsigned long* a, unsigned long* b, unsigned long*c, long n)
{
	/*init index variables*/
	long i=0, j=0, k=0;
	unsigned long sum, sum1, sum2, sum3, sum4, sum5, sum6, sum7;
	long end = n - (n % 8);
	for (i = 0; i < n; ++i)
	{
		long in = i*n;
		for (j = 0; j < n; ++j)
		{
		/*assign zero values to sums*/
			sum = 0;
			sum1 = 0;
			sum2 = 0;
			sum3 = 0;
			sum4 = 0;
			sum5 = 0;
			sum6 = 0;
			sum7 = 0;
			/*Make sure matrix is of correct size first*/
			if (n >= 8)
			{
				for (k = 0; k < end; k+=8)
				{
					sum = sum + a[in+k] * b[k*n+j];
					sum1 = sum1 + a[in+(k+1)] * b[(k+1)*n+j];
					sum2 = sum2 + a[in+(k+2)] * b[(k+2)*n+j];
					sum3 = sum3 + a[in+(k+3)] * b[(k+3)*n+j];
					sum4 = sum4 + a[in+(k+4)] * b[(k+4)*n+j];
					sum5 = sum5 + a[in+(k+5)] * b[(k+5)*n+j];
					sum6 = sum6 + a[in+(k+6)] * b[(k+6)*n+j];
					sum7 = sum7 + a[in+(k+7)] * b[(k+7)*n+j];
				}
			
				sum = sum + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
			}
			/*for loop that starts at tail cases and handles them one by one*/
			for (k = end; k < n; ++k)
			{
				sum = sum + a[in+k] * b[k*n+j];
			}
			c[in+j] = sum;
		}
	}
}
