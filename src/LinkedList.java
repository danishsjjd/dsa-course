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
    }

    public void addLast(int item) {
        var node = new Node(item);
        last.next = node;
        last = node;

        if (first == null)
            first = node;
    }

    public void deleteFirst() {
        if (first == null)
            return;

        Node nextNode = first.next;
        first.next = null;
        first = nextNode;
    }

    public void deleteLast() {
        walkList(first, x -> {
            if (x == first && x == last) {
                first = null;
                last = null;
                x.next = null;
                return true;
            }

            Node nextNode = x.next;

            if (nextNode == last) {
                last = x;
                x.next = null;
                return true;
            }

            return false;
        });
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

    public void print() {
        walkList(first, x -> {
            System.out.println(x.value);
            return false;
        });
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

        integers.deleteFirst();
        integers.deleteLast();

        System.out.println(integers.indexOf(2));
        System.out.println(integers.indexOf(1));
        integers.print();
    }
}