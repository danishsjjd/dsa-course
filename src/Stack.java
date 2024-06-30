import java.util.Stack;

class ReverseString {
    public static String reverse(String string) {
        var stringStack = new Stack<Character>();

        for (char ch : string.toCharArray())
            stringStack.push(ch);

        StringBuffer reversed = new StringBuffer();

        while (!stringStack.empty())
            reversed.append(stringStack.pop());

        return reversed.toString();
    }

    public static void test() {
        var string = ReverseString.reverse("abcd");
        System.out.println(string);
    }
}

class Expression {
    public static boolean isBalanced(String string) {
        if (string == null)
            throw new IllegalArgumentException();

        Stack<Character> charStack = new Stack<>();
        final String OPENING_EXPRESSION = "[{(<";
        final String CLOSING_EXPRESSION = "]})>";

        for (char ch : string.toCharArray()) {
            if (OPENING_EXPRESSION.indexOf(ch) != -1)
                charStack.push(ch);
            if (CLOSING_EXPRESSION.indexOf(ch) != -1) {
                if (charStack.empty())
                    return false;

                Character top = charStack.pop();
                if (OPENING_EXPRESSION.charAt(CLOSING_EXPRESSION.indexOf(ch)) != top)
                    return false;

            }
        }

        return charStack.empty();
    }

    public static void test() {
        System.out.println(Expression.isBalanced("(([1], + <2>){c})[a]"));
    }
}

class TestStack {
    public static void main(String[] args) {
        ReverseString.test();
        Expression.test();
    }
}
