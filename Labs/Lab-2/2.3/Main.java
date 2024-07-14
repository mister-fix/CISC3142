// A Divide and Conquer based Java
// program for maximum subarray sum
// problem
import java.util.*;

class GFG {

	// Find the maximum possible sum in arr[]
	// such that arr[m] is part of it
	static int maxCrossingSum(int arr[], int l, int m,
							int h)
	{
		// Include elements on left of mid.
        System.out.println("left side");
		int sum = 0;
		int left_sum = Integer.MIN_VALUE;
		for (int i = m; i >= l; i--) {
            System.out.println("m: " + m);
            System.out.println("i: " + i);
			sum = sum + arr[i];
            System.out.println("sum : " + sum);
			if (sum > left_sum)
				left_sum = sum;
                System.out.println("left_sum is: " + left_sum);

            System.out.println("--------------");
		}

		// Include elements on right of mid
        System.out.println("\n right side");
		sum = 0;
		int right_sum = Integer.MIN_VALUE;
		for (int i = m; i <= h; i++) {
            System.out.println("Middle is: " + m);
            System.out.println("i is: " + i);
			sum = sum + arr[i];
            System.out.println("sum is : " + sum);
			if (sum > right_sum)
				right_sum = sum;
                System.out.println("right_sum is: " + right_sum);

            System.out.println("--------------");
		}

		// Return sum of elements on left
		// and right of mid
		// returning only left_sum + right_sum will fail for
		// [-2, 1]
		return Math.max(left_sum + right_sum - arr[m],
						Math.max(left_sum, right_sum));
	}

	// Returns sum of maximum sum subarray
	// in aa[l..h]
	static int maxSubArraySum(int arr[], int l, int h)
	{
		//Invalid Range: low is greater than high
		if (l > h)
			return Integer.MIN_VALUE;
		// Base Case: Only one element
		if (l == h)
			return arr[l];

		// Find middle point
		int m = (l + h) / 2;

		/* Return maximum of following three
		possible cases:
		a) Maximum subarray sum in left half
		b) Maximum subarray sum in right half
		c) Maximum subarray sum such that the
		subarray crosses the midpoint */
		return Math.max(
			Math.max(maxSubArraySum(arr, l, m-1),
					maxSubArraySum(arr, m + 1, h)),
			maxCrossingSum(arr, l, m, h));
	}

	/* Driver program to test maxSubArraySum */
	public static void main(String[] args)
	{
		int arr[] = {10, 3, 15, 5, 19};
		int n = arr.length;
		int max_sum = maxSubArraySum(arr, 0, n - 1);

		System.out.println("Maximum contiguous sum is "
						+ max_sum);
	}
}
// This code is contributed by Prerna Saini
