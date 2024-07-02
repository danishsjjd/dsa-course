import java.util.Arrays;

public class TwoStacks {
  private int top1;
  private int top2;
  private int[] items;

  public TwoStacks(int capacity) {
    if (capacity <= 0)
      throw new IllegalArgumentException("capacity must be 1 or greater.");

    items = new int[capacity];
    top1 = -1;
    top2 = capacity;
  }

  public void push1(int item) {
    if (isFull1())
      throw new IllegalStateException();

    items[++top1] = item;
  }

  public int pop1() {
    if (isEmpty1())
      throw new IllegalStateException();

    return items[top1--];
  }

  public boolean isEmpty1() {
    return top1 == -1;
  }

  public boolean isFull1() {
    return top1 + 1 == top2;
  }

  public void push2(int item) {
    if (isFull2())
      throw new IllegalStateException();

    items[--top2] = item;
  }

  public int pop2() {
    if (isEmpty2())
      throw new IllegalStateException();

    return items[top2++];
  }

  public boolean isEmpty2() {
    return top2 == items.length;
  }

  public boolean isFull2() {
    return top2 - 1 == top1;
  }

  @Override
  public String toString() {
    return Arrays.toString(items);
  }
}

class TestTwoStack {
  public static void main(String[] args) {
    var twoStack = new TwoStacks(5);
    twoStack.push1(1);
    twoStack.push2(2);
    System.out.println(twoStack);
    twoStack.push1(3);
    twoStack.push2(4);
    System.out.println(twoStack);
    twoStack.push2(6);
    System.out.println(twoStack);
    twoStack.pop1();
    twoStack.push1(2);
    System.out.println(twoStack);
  }
}