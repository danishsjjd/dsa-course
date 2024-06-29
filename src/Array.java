import java.util.Arrays;

public class Array<T> {
    private T[] items;
    private int count;

    public Array(int length) {
        items = (T[]) new Object[length];
    }

    private void resizeIfRequired() {
        if (items.length == count) {
            T[] newItems = (T[]) new Object[count * 2];

            for (int i = 0; i < count; i++)
                newItems[i] = items[i];

            items = newItems;
        }
    }

    public void insert(T item) {
        resizeIfRequired();

        items[count++] = item;
    }

    public void insertAt(T item, int index) {
        if (index < 0 || index > count)
            throw new IllegalArgumentException();

        resizeIfRequired();

        for (int i = count - 1; i >= index; i--)
            items[i + 1] = items[i];

        items[index] = item;
        count++;
    }

    public void removeAt(int index) {
        if (index < 0 || index > count)
            throw new IllegalArgumentException();

        for (int i = index; i < count; i++)
            items[i] = items[i + 1];

        --count;
    }

    public int indexOf(T item) {
        for (int i = 0; i <= count; i++)
            if (item == items[i])
                return i;

        return -1;
    }

    public void print() {
        System.out.println(Arrays.toString(items));
    }

    public T max() {
        if (count == -1)
            throw new IllegalAccessError();

        if (count == 0)
            return items[0];

        T max = items[0];

        for (T t : items) {
            if ((int) t > (int) max)
                max = t;
        }

        return max;
    }

    public T[] reverse() {
        T[] newArray = (T[]) new Object[items.length];

        int activeIndex = -1;
        for (int i = count; i >= 0; i--) {
            newArray[++activeIndex] = items[i];
        }

        return newArray;
    }

    public Array intersect(Array other) {
        var intersection = new Array(count);

        for (T item : items)
            if (other.indexOf(item) >= 0)
                intersection.insert(item);

        return intersection;
    }
}

class Test {
    public static void main(String[] args) {
        Array<Integer> numbers = new Array<>(2);

        numbers.insert(1);
        numbers.insert(2);
        numbers.insert(3);

        numbers.insertAt(99, 2);

        numbers.print();
    }
}