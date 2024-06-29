
import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Array<T> {
    private T[] items;
    private int count;

    public Array(int length) {
        items = (T[]) new Object[length];
    }

    public T[] getItems() {
        T[] newItems = (T[]) new Object[count];
        for (int i = 0; i < count; i++) {
            newItems[i] = items[i];
        }
        return newItems;
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

    public void insertAt(int index, T item) {
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

        for (int i = index; i < count; i++) {
            var nextIndex = i + 1;
            if (items.length != nextIndex)
                items[i] = items[nextIndex];
        }

        count--;
    }

    public int indexOf(T item) {
        for (int i = 0; i < count; i++)
            if (item == items[i])
                return i;

        return -1;
    }

    public T max() {
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
        T[] newItems = (T[]) new Object[count];

        for (int i = 0; i < count; i++)
            newItems[i] = items[count - i - 1];

        return newItems;
    }

    public Array<T> intersect(Array<T> other) {
        var intersection = new Array<T>(count);

        for (int i = 0; i < count; i++) {
            if (other.indexOf(items[i]) >= 0) {
                intersection.insert(items[i]);
            }
        }

        return intersection;
    }
}

class TestArray {
    public static void main(String[] args) {
        Array<Integer> numbers = new Array<>(1);

        numbers.insert(99);
        numbers.insert(2);
        numbers.insert(4);

        numbers.insertAt(2, 3);
        numbers.removeAt(0);

        System.out.println(Arrays.toString(numbers.getItems()));
        System.out.printf("reverse %s\n", Arrays.toString(numbers.reverse()));
        System.out.printf("index of `1` is %s.\n", Integer.toString(numbers.indexOf(1)));
        System.out.printf("index of `2` is %s.\n", Integer.toString(numbers.indexOf(2)));
        System.out.printf("index of `4` is %s.\n", Integer.toString(numbers.indexOf(4)));
        System.out.printf("max %s.\n", Integer.toString(numbers.max()));

        Array<Integer> moreNumbers = new Array<>(4);

        moreNumbers.insert(4);
        moreNumbers.insert(5);

        System.out.println(Arrays.toString(numbers.intersect(moreNumbers).getItems()));
    }
}
