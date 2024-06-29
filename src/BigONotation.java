class BigONotation {
    // ---------------------------------------------------
    // Runtime complexity
    public static void log1(int[] numbers) {
        // O(1)
        // Not counting the exact number of operations; just looking at how the
        // algorithm slows down as the input size increases. In this method, whether
        // there is one million items, it runs in constant time. So, the complexity is
        // O(1), not O(n).

        System.out.println(numbers[0]); // O(1)
        System.out.println(numbers[0]); // O(1)
    }

    public static void log2(int[] numbers, String[] names) {
        // O(n)
        // when using BigO notation we drop the constant like O(2 + 2n) will be just
        // O(n). if arrays have one millions input adding two extra operation doesn't
        // really have any significant impact on the cost of our algorithm. all we need
        // here is approx cost of the algorithm relative to it's input size.

        System.out.println("Starting loop..."); // O(1)

        for (int number : numbers) { // O(n)
            System.out.println(number);
        }
        for (int number : numbers) {// O(n)
            System.out.println(number);
        }

        System.out.println("End loop"); // O(1)

        for (String name : names) { // O(n)
            System.out.println(name);
        }
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
    }

    // ---------------------------------------------------
    // Space complexity
    // A trade off between saving time and saving space.
    // eg.
    // - in server we have more space but less time
    // - in smart watch, we have less space but only one end user will use watch at
    // a time
    public static void log3(String[] names) {
        // This method has a loop that is independent of the size of the input, so the
        // space complexity is O(1).
        for (int i = 0; i < names.length; i++) {
            System.out.println("Hi " + names[i]);
        }

        // O(n) space
        String[] _copy = new String[names.length];
    }
}
