import java.util.Stack;

public class MinStack {
  private Stack<Integer> stack = new Stack<Integer>();
  private Stack<Integer> minStack = new Stack<Integer>();

  public void push(int item) {
    stack.push(item);

    if (minStack.isEmpty())
      minStack.push(item);
    else if (item < minStack.peek())
      minStack.push(item);
  }

  public int pop() {
    if (stack.isEmpty())
      throw new IllegalStateException();

    var top = stack.pop();

    if (minStack.peek() == top)
      minStack.pop();

    return top;
  }

  public int min() {
    return minStack.peek();
  }
}

class TestMinStack {
  public static void main(String[] args) {
    var stack = new MinStack();
    stack.push(5);
    stack.push(2);
    stack.push(10);
    stack.push(1);
    System.out.println(stack.min());
    System.out.println(stack.pop());
    System.out.println(stack.min());
  }
}