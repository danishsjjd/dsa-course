import java.util.Arrays;
import java.util.function.Function;

public class LinkedList {
    class Node {
        private int value;
        private Node next;

        public Node(int item) {
            value = item;
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
        System.out.printf("index of `1` is %s.\n", Integer.toString(integers.indexOf(1)));
        System.out.printf("index of `2` is %s.\n", Integer.toString(integers.indexOf(2)));
        System.out.printf("size %s.\n", Integer.toString(integers.size()));
        integers.reverse();
        System.out.printf("reverse %s\n", Arrays.toString(integers.toArray()));
    }
}