>>> 1 :) FIND MMI 
// |||||||||||||||||||||||||||||||||||||||||||   1  # MMI #|||||||||||||||||||||||||||||||||||||||||||||||||||||
//Fermat’s little theorem states that if m is a prime and a is an integer co-prime to m, 
//then ap − 1 will be evenly divisible by m. That is a^{m-1} \equiv 1 \pmod{m}. or a^{m-2} \equiv a^{-1} \pmod{m}. 
//Here’s a sample C++ code:

/* This function calculates (a^b)%MOD */
int pow(int a, int b, int MOD) {
int x = 1, y = a;
	while(b > 0) {
		if(b%2 == 1) {
			x=(x*y);
			if(x>MOD) x%=MOD;
		}
		y = (y*y);
		if(y>MOD) y%=MOD;
		b /= 2;
	}
	return x;
}

int modInverse(int a, int m) {
    return pow(a,m-2,m);
}
The time complexity of the above codes is O(log(m)).

// If m is not a prime we can use Euler’s Theorem
//inverse(i) = (inverse(i/factor(i)) * inverse(factor(i))) % m

vector<int> inverseArray(int n, int m) {
	vector<int> modInverse(n + 1,0);
	modInverse[1] = 1;
	for(int i = 2; i <= n; i++) {
		modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
	}
	return modInverse;
}

The time complexity of the above code is O(n).
