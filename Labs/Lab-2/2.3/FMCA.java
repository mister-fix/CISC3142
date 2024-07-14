// A Divide and Conquer based Java
// program for maximum subarray sum
// problem
import java.util.*;

class FMCA {

	// Find the maximum possible sum in arr[]
	// such that arr[m] is part of it
	static int maxCrossingSum(int arr[], int l, int m,
							int h)
	{
		// Include elements on left of mid.
		int sum = 0;
		int left_sum = Integer.MIN_VALUE;

		for (int i = m; i >= l; i--) {
            System.out.println("Index is: " + i);
			sum = sum + arr[i];
			if (sum > left_sum)
				left_sum = sum;
                System.out.println("Sum is: " + sum);
                System.out.println("Left_max_sum is: " + sum);
		}

		// Include elements on right of mid
		sum = 0;
		int right_sum = Integer.MIN_VALUE;
		for (int i = m; i <= h; i++) {
            System.out.println("Index is: " + i);
			sum = sum + arr[i];
			if (sum > right_sum)
				right_sum = sum;
                System.out.println("Sum is: " + sum);
                System.out.println("Right_max_sum is: " + sum);
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
		int arr[] = {-7, 12, -10, 14};
		int n = arr.length;
		int max_sum = maxSubArraySum(arr, 0, n - 1);

		System.out.println("Maximum contiguous sum is "
						+ max_sum);
	}
}
// This code is contributed by Prerna Saini

Stephen Mwingira
Professor Taylan
CISC.3220

Homework 6

Sorry professor, I had to try this homework again, I hope that this will still count, but I think this is the correct approach, below is the writeup of my thinking, the following page will show the steps more succinctly.

My original mistake for the array to use for the algorithm pseudo code was using the price values for each given day in the diagram, instead of using the difference in price from day to day. Difference in price from day 0 to day 1 is -7, difference in price from day 1 to day 2 is 12, difference in price from day 2 to day 3 is -10, and the difference in price from day 3 to day 4 is 14. So array A should have had values of [-7, 12, -10, 14], which will be the array we will use going forward.

We need to divide array A into two parts, left side subarray and right side subarray. The left-subarray will be [-7, 12], which will be further divided into two more subarrays, left and right subarrays, [-7] and [12]. The maximum for FMS(A, 1, 1) is -7, while the maximum for FMS(A, 2, 2) is 12. This will be returned up for the left side as (1, 1, -7), while for the right subarray with value 12 will be returned for (2, 2, 12). Now we need to find the maximum left subarray value, so FMS(A, 1, 2), which will give us a maximum value of 5, (-7, 12, 5). Now that we have three values, we will compare and take the largest of them, in this instance the largest sum we found is 12 from (A, 2, 2) -> (2, 2, 12), so this will be returned to the first FMS call for the left subarray.

The right subarray for array A will be [-10, 14], which will be further divided into two more subarrays, left and right subarrays, [-10] and [14]. The maximum for FMS(A, 3, 3) is -10, so we will return (3, 3, -10), on the right the maximum FMS(A, 4, 4) is 14, so we will return (4, 4, 14). We need to find the crossing subarray maximum now FMCS(A, 3, 4), the segment will be [-10, 14], which will give us a maximum value of 4, (3, 4, 4). Now that we have our three subarray values for array A’s right side, we will compare the three and take the largest of them. In this instance, the largest sum we found is 14 from (A, 4, 4) -> (4, 4, 14), so this will be returned up to the FMS call for A’s right subarray.

Now we need to find the maximum crossing subarray value for the entire array A. This will be a loop testing contiguous values from array A, starting from the first index to the last, when we have a subarray of contiguous values of A to the maximum, we will then start removing values from the left. So we will start at A[1] -> [-7] will return -7, then A[1] to A[2] -> [-7, 12] will return 5, then A[1] to A[3] -> [-7, 12, -10] will return -5, then A[1] to A[4] -> [-7, 12, -10, 14] will return 9. Now we will reduce the size of the subarray plucking from the left, so A[2] to A[4] -> [12, -10, 14] will return 16, then A[3] to A[4] -> [-10, 14] will return 4, and finally A[4] -> [14] will return 14. From this we can determine that the largest crossing subarray value for array A is 16 found from FMCS(A, 2, 4).
We now have all of the values needed to determine the maximum subarray value for array A. Our left-subarray maximum value is 12, our right-subarray maximum value is 14, and our crossing subarray maximum value is 16, from this we can determine that the crossing subarray maximum is array A’s largest subarray value, so the final answer is (2, 4, 16).

In conclusion, to maximize profit, we will have to purchase on day 2 and sell on day 4 to make the most amount of money of $16.

—-

A = [-7, 12, -10, 14]

ll, lh, ls = FMS(A, 1, 2)
	FMS(A, 1, 1) → returns (1, 1, -7)
	FMS(A, 2, 2) → returns (2, 2, 12)
	FMS(A, 1, 2) → returns (1, 2, 5)

rl,rh, rs = FMS(A, 3, 4)
	FMS(A, 3, 3) → returns (3, 3, -10)
	FMS(A, 4, 4) → returns (4, 4, 14)
	FMS(A, 3, 4) → returns (3, 4, 14)

cl, ch, cs = FMS(A, 1, 2, 4) → returns (2, 4, 16)
	Finding max-left value
		Loop (from 2 to 1)
			Sum is current sum (0) plus value at A[2], which gives us 12
			12 is larger than left_sum, so we set left_sum = 12
			Max-left will be index of sum, so 2
		Loop (from 2 to 2)
			Sum is current sum plus value at A[1], which gives us 5
			5 is not larger than 12, so left_max value stays same and we exit loop

	Finding right-max value
		Loop (from 3 to 4)
			Sum is -10
			-10 is larger than right_sum, so we set right_sum to -10
			Max_right will be index of sum, so 3
		Loop (from 4 to 4)
			Sum is current sum plus value at A[4], which gives us 4
			4 is larger than -10, so we set max_right value to value of sum, 4
	12 - 10 + 14 = 16
