import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Stack {
  private int[] items = new int[5];
  private int count;

  public void push(int item) {
    if (count == items.length)
      throw new StackOverflowError();

    items[count++] = item;
  }

  public int pop() {
    if (count == 0)
      throw new IllegalStateException();

    return items[--count];
  }

  public int peek() {
    if (count == 0)
      throw new IllegalStateException();

    return items[count - 1];
  }

  public boolean empty() {
    return count == 0;
  }

  @Override
  public String toString() {
    var content = Arrays.copyOfRange(items, 0, count);
    return Arrays.toString(content);
  }
}

class Reverse {
  public static String reverseString(String string) {
    StringBuffer reversed = new StringBuffer();
    for (int i = (string.length() - 1); i >= 0; i--)
      reversed.append(string.charAt(i));

    return reversed.toString();

    // not my implementation
    // var stringStack = new Stack<Character>();

    // for (char ch : string.toCharArray())
    // stringStack.push(ch);

    // StringBuffer reversed = new StringBuffer();

    // while (!stringStack.empty())
    // reversed.append(stringStack.pop());

    // return reversed.toString();
  }

  public static void reverseQueue(Queue<Integer> queue) {
    var queueStack = new Stack();

    while (!queue.isEmpty())
      queueStack.push(queue.remove());

    while (!queueStack.empty())
      queue.add(queueStack.pop());
  }

  public static void test() {
    String string = "abc";
    var reversedString = Reverse.reverseString(string);
    System.out.printf("original string `%s` reversed string `%s`\n", string, reversedString);
    System.out.println("------------------------------------------------");

    Queue<Integer> queue = new ArrayDeque<>();
    queue.add(10);
    queue.add(20);
    queue.add(30);
    System.out.printf("queue: %s\n", queue);
    Reverse.reverseQueue(queue);
    System.out.printf("reversedQueue: %s\n", queue);
    System.out.println("------------------------------------------------");
  }
}

class Expression {
  public static boolean isBalanced(String string) {
    if (string == null)
      throw new IllegalArgumentException();

    var charStack = new Stack();
    final String OPENING_EXPRESSION = "[{(<";
    final String CLOSING_EXPRESSION = "]})>";

    for (char ch : string.toCharArray()) {
      if (OPENING_EXPRESSION.indexOf(ch) != -1)
        charStack.push(ch);
      if (CLOSING_EXPRESSION.indexOf(ch) != -1) {
        if (charStack.empty())
          return false;

        Character top = (char) charStack.pop();
        if (OPENING_EXPRESSION.charAt(CLOSING_EXPRESSION.indexOf(ch)) != top)
          return false;

      }
    }

    return charStack.empty();
  }

  public static void test() {
    String expression = "(([1], + <2>){c})[a]";
    System.out.printf("this `%s` expression is %s balanced\n", expression, Expression.isBalanced(expression));
  }
}

class TestStack {
  public static void main(String[] args) {
    Reverse.test();
    Expression.test();
  }
}
