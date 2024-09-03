public class Driver {
    public static void main(String[] args) {

        genericLL<Integer> list = new genericLL<Integer>();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(5);
        list.insert(6);
        list.print();
        list.goToNodeWithData(2);
        list.deleteCurr();
        list.goToNodeWithData(5);
        list.deleteCurr();
        list.print();

    }
}
