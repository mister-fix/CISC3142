public class Rational {
    // Numerator and denominator
    private int num, denom;

    // Arg constructor
    Rational(int num, int denom) {
        if(denom == 0) {
            throw new RationalException("Cannot set denominator to 0.");
        }

        this.num = num;
        this.denom = denom;

        normalize(this);
    }

    Rational(int num) {
        this.num = num;
        this.denom = 1;
    }

    // No-arg constructor (default)
    Rational() {
        // num = 0;
        denom = 1;
    }

    // Normalization method
    private void normalize(Rational r) {
        int val = gcd(r.getNumerator(), r.getDenominator());
        r.num = r.getNumerator() / val;
        r.denom = r.getDenominator() / val;
    }

    // Copy constructor
    Rational(Rational r) {
        this.num = r.getNumerator();
        this.denom = r.getDenominator();

        normalize(this);
    }

    // Add method
    Rational add(Rational r) {
        Rational result = new Rational();
        result.num = (this.num * r.denom) + (this.denom * r.num);
        result.denom = this.denom * r.denom;

        normalize(result);
        return result;
    }

    // Subtract method
    Rational sub(Rational r) {
        Rational result = new Rational();
        result.num = (this.num * r.denom) - (this.denom * r.num);
        result.denom = (this.denom * r.denom);

        normalize(result);
        return result;
    }

    // Multiplication method
    Rational mul(Rational r) {
        Rational result = new Rational(this.num * r.num, this.denom * r.denom);

        normalize(result);
        return result;
    }

    // Division method
    Rational div(Rational r) {
        Rational result = new Rational(this.num * r.denom, this.denom * r.num);
        
        normalize(result);
        return result;
    }

    // Add in place method
    Rational addInPlace(Rational r) {
        Rational result = this.add(r);
        this.num = result.getNumerator();
        this.denom = result.getDenominator();

        return result;
    }

    // Subtract in place method
    Rational subInPlace(Rational r) {
        Rational result = this.sub(r);
        this.num = result.getNumerator();
        this.denom = result.getDenominator();

        return this;
    }

    // Multiply in place method
    Rational mulInPlace(Rational r) {
        Rational result = this.mul(r);
        
        this.num = result.getNumerator();
        this.denom = result.getDenominator();

        return this;
    }

    // Divide in place method
    Rational divInPlace(Rational r) {
        Rational result = this.div(r);

        this.num = result.getNumerator();
        this.denom = result.getDenominator();

        return this;
    }

    // Negate method
    Rational negate() {
        return new Rational(-num, denom);
    }

    // Inverse method
    Rational inverse() {
        return new Rational(this.denom, this.num);
    }

    // Get numerator method
    int getNumerator() {
        return num;
    }

    // Get denominator method
    int getDenominator() {
        return denom;
    }

    // Comparison method
    int compareTo(Rational r) {
        int top = this.num * r.getDenominator();
        int bottom = this.denom * r.getNumerator();

        if(top == bottom) {
            return 0;
        }
        else if (top < bottom) {
            return -1;
        }
        else {
            return 1;
        }
    }

    // Equals method
    boolean equals(Rational r) {
        return this.num == r.num && this.denom == r.denom;
    }

    // toString method
    public String toString() {
        if(denom == 1) {
            return num + "";
        }
        else {
            return num + "/" + denom;
        }
    }

    // GCD method
    private static int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
}

// Rational div(Relational r) {
//     return this.mul(r.inverse());
// }

// int newNum = this.num * r.getDenominator() + this.denom * r.getNumerator();
// int newDenom = this.denom * r.getDenominator();


// this.num = this.getNumerator() * -1;
// this.denom = this.getDenominator();