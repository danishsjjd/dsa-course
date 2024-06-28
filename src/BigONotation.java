class BigONotation {
    // ---------------------------------------------------
    // Runtime complexity
    public static void log1(int[] numbers) {
        System.out.println(numbers[0]);
        System.out.println(numbers[0]);
        // we don't count the number of operations we just wanna know how much algorithm
        // slow down as the input grows larger. in this method, if we have one or one
        // million items our method run in constant time so the complexity of this is
        // O(1) instead of O(2)
    }

    public static void log2(int[] numbers, String[] names) {
        System.out.println("Starting loop..."); // O(1)

        for (int number : numbers) { // O(n)
            System.out.println(number);
        }
        for (int number : numbers) {// O(n)
            System.out.println(number);
        }

        System.out.println("End loop"); // O(1)

        // when using BigO notation we drop the constant like O(2 + 2n) will be just
        // O(n) if arrays have one millions input adding two extra operation doesn't
        // really have any significant impact on the cost of your algorithm.

        // all we need here is approx of the cost of the algorithm relative to it's
        // input size.

        for (String name : names) { // O(n)
            System.out.println(name);
        }

        // complexity will still be O(n) because the runtime of this method increase
        // linearly
    }

    public static void log3(int[] numbers) {
        // O(n^3)

        for (int number : numbers) { // O(n)
            System.out.println(number);
        }

        for (int first : numbers) { // O(n)
            for (int second : numbers) { // O(n)
                for (int third : numbers) { // O(n)
                    System.out.printf("First, " + first + " second, " + second + " and third ", third);
                }
            }
        }

        // O(n + (n*n*n)) -> O(n + n ^3) -> O(n^3)
        // all we need is approximation not an exact value.
    }

    // ---------------------------------------------------
    // Space complexity
    // we have to do a trade off between saving time and saving space.
    // eg.
    // - in server we have more space but less time
    // - in smart watch, we have less space but only one end user will use watch at
    // a time
    public static void log3(String[] names) {
        // In this method, we are declearing loop method and this is independent of the
        // size of input so the space complexity of this is O(1) space
        for (int i = 0; i < names.length; i++) {
            System.out.println("Hi " + names[i]);
        }

        // O(n) space
        String[] _copy = new String[names.length];
    }
}
