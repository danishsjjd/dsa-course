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

    public void addFirst(int item) {
        var node = new Node(item);
        node.next = first;
        first = node;

        if (last == null)
            last = node;

        size++;
    }

    public void addLast(int item) {
        var node = new Node(item);
        last.next = node;
        last = node;

        if (first == null)
            first = node;

        size++;
    }

    public void removeFirst() {
        if (first == null)
            return;

        Node nextNode = first.next;
        first.next = null;
        first = nextNode;

        size--;
    }

    public void removeLast() {
        Node node = first;
        if (node == null)
            return;

        if (first == last)
            first = last = node.next = null;
        else {
            Node previousNode = getPrevious(last);
            last = previousNode;
            last.next = null;
        }

        size--;
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

        System.out.println(Arrays.toString(integers.toArray()));
        System.out.printf("index of `1` is %s.\n", Integer.toString(integers.indexOf(1)));
        System.out.printf("index of `2` is %s.\n", Integer.toString(integers.indexOf(2)));
        System.out.printf("size %s.\n", Integer.toString(integers.size()));
    }
}