import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class CharFinder {
    public static Character finder(String str) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();

        var chars = str.toCharArray();
        for (Character ch : chars) {
            Integer value = map.getOrDefault(ch, 0);
            map.put(ch, value + 1);
        }

        for (char c : chars) {
            if (map.get(c) == 1)
                return c;
        }

        return Character.MIN_VALUE;
    }

    public char findFirstRepeatedChar(String str) {
        Set<Character> set = new HashSet<>();

        for (var ch : str.toCharArray()) {
            if (set.contains(ch))
                return ch;

            set.add(ch);
        }

        return Character.MIN_VALUE;
    }
}

class TestCharFinder {
    public static void main(String[] args) {
        System.out.println(CharFinder.finder("a green apple"));
    }
}
