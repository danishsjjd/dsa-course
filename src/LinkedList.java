import java.util.Arrays;
import java.util.function.Function;

public class LinkedList {
    class Node {
        private int value;
        private Node next;

        public Node(int item) {
            value = item;
        }

        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }

    private Node first;
    private Node last;
    private int size;

    public static void walkList(Node node, Function<Node, Boolean> cb) {
        if (node == null)
            return;

        boolean isForceStop = cb.apply(node);
        if (isForceStop)
            return;

        walkList(node.next, cb);
    }

    private Node getPrevious(Node node) {
        Node current = first;
        while (current != null) {
            if (current.next == node)
                return current;
            current = current.next;
        }
        return null;
    }

    private boolean isEmpty() {
        return first == null;
    }

    public void addFirst(int item) {
        var node = new Node(item);

        if (isEmpty())
            first = last = node;
        else {
            node.next = first;
            first = node;
        }

        size++;
    }

    public void addLast(int item) {
        var node = new Node(item);

        if (isEmpty())
            first = last = node;
        else {
            last.next = node;
            last = node;
        }

        size++;
    }

    public void removeFirst() {
        if (isEmpty())
            return;

        Node nextNode = first.next;
        first.next = null;
        first = nextNode;

        size--;
    }

    public void removeLast() {
        if (isEmpty())
            return;

        Node node = first;
        if (first == last)
            first = last = node.next = null;
        else {
            Node previousNode = getPrevious(last);
            last = previousNode;
            last.next = null;
        }

        size--;
    }

    public boolean contains(int number) {
        return indexOf(number) != -1;
    }

    public int indexOf(int number) {
        Node node = first;
        int count = 0;

        while (node != null) {
            if (node.value == number)
                return count;

            node = node.next;
            ++count;
        }

        return -1;
    }

    public int size() {
        return size;
    }

    public int[] toArray() {
        int[] array = new int[size];
        Node node = first;
        int index = 0;

        while (node != null) {
            array[index++] = node.value;
            node = node.next;
        }

        return array;
    }

    // reverse in place
    public void reverse() {
        if (isEmpty())
            return;

        Node previous = first;
        Node current = first.next;
        while (current != null) {
            Node next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }

        last = first;
        last.next = null;
        first = previous;
    }

    public Node getKthFromTheEnd(int kth) {
        if (isEmpty())
            return null;

        Node current = first;
        Node KthNode = null;
        int count = 1;

        while (current != null) {
            if (count == kth) {
                if (KthNode != null)
                    KthNode = KthNode.next;
                else
                    KthNode = first;
            } else
                count++;

            current = current.next;
        }

        return KthNode;
    }

    public Node getKthFromTheEndOptimized(int kth) {
        if (isEmpty() || kth > size)
            return null;

        int offset = size - kth;
        int count = 0;
        Node current = first;
        Node kthNode = null;

        while (current != null) {
            if (count == offset) {
                kthNode = current;
                break;
            }

            current = current.next;
            count++;
        }

        return kthNode;
    }

    public void printMiddle() {
        if (isEmpty())
            return;

        boolean isEven = size == 2 ? true : (size / 2f) % 2 == 0;
        int center = size / 2 + (isEven ? 0 : 1);
        var centerNods = new Node[2];
        Node current = first;
        int count = 1;

        while (current != null) {
            if (count == center) {
                centerNods[0] = current;
                if (!isEven)
                    break;
            } else if (center < count) {
                centerNods[1] = current;
                break;
            }

            current = current.next;
            ++count;
        }

        if (!isEven) {
            System.out.printf("middle node: %s\n", centerNods[0]);
            return;
        }

        System.out.printf("middle nodes: %s\n", Arrays.toString(centerNods));
    }

    // --------- not my implementation
    public boolean hasLoop() {
        var slow = first;
        var fast = first;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    public static LinkedList createWithLoop() {
        var list = new LinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);

        // Get a reference to 30
        var node = list.last;

        list.addLast(40);
        list.addLast(50);

        // Create the loop
        list.last.next = node;

        return list;
    }

    // public int getKthFromTheEnd(int k) {
    // if (isEmpty())
    // throw new IllegalStateException();

    // var a = first;
    // var b = first;
    // for (int i = 0; i < k - 1; i++) {
    // b = b.next;
    // if (b == null)
    // throw new IllegalArgumentException();
    // }
    // while (b != last) {
    // a = a.next;
    // b = b.next;
    // }
    // return a.value;
    // }

    // public void printMiddle() {
    // if (isEmpty())
    // throw new IllegalStateException();

    // var a = first;
    // var b = first;
    // while (b != last && b.next != last) {
    // b = b.next.next;
    // a = a.next;
    // }

    // if (b == last)
    // System.out.println(a.value);
    // else
    // System.out.println(a.value + ", " + a.next.value);
    // }
}

class TestLinkedList {
    public static void main(String[] args) {
        var integers = new LinkedList();

        integers.addFirst(3);
        integers.addFirst(2);
        integers.addFirst(1);

        integers.addLast(4);
        integers.addLast(5);
        integers.addLast(6);

        integers.removeFirst();
        integers.removeLast();

        System.out.printf("Array %s\n", Arrays.toString(integers.toArray()));
        integers.printMiddle();
        System.out.printf("index of `2` is %s.\n", Integer.toString(integers.indexOf(2)));
        System.out.printf("size %s.\n", Integer.toString(integers.size()));
        System.out.printf("3th kth %s == %s.\n", integers.getKthFromTheEnd(3), integers.getKthFromTheEndOptimized(3));
        integers.reverse();
        System.out.printf("reverse %s\n", Arrays.toString(integers.toArray()));
        System.out.printf("has loop %s\n", integers.hasLoop());
        System.out.println("------------------------------- Loop LinkedList --------------------------------");
        var linkedListLoop = LinkedList.createWithLoop();
        System.out.printf("has loop %s\n", linkedListLoop.hasLoop());
    }
}