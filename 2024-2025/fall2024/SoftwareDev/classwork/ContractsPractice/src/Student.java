public class Student
{
    private String name;
    private int age;
    private String email;

    /**
     * Parameterized constructor for Students. Takes in 3 parameters.
     * @param name name of Student, String
     * @param age age of Student, int
     * @param email email of Student, String, contains the @ sign
     *
     * @pre name != null AND name != "" AND age > 0 AND [email contains '@']
     * and email != null
     *
     * @post this.name = name AND this.age = age AND this.email = email
     */
    public Student(String name, int age, String email)
    {
        this.name = name;
        this.age = age;
        this.email = email;
    }

    /**
     * Getter for name
     *
     * @pre none
     * @post getName = name AND name = #name AND age = #age AND email = #email
     * @return name
     */
    public String getName()
    {
        return name;
    }

    public int getAge()
    {
        return age;
    }

    public String getEmail()
    {
        return email;
    }

    public void setName(String aName)
    {
        this.name = aName;
    }

    public void setAge(int anAge)
    {
        this.age = anAge;
    }

    public void setEmail(String anEmail)
    {
        this.email = anEmail;
    }

    /**
     * Prints student information where each variable is printed to its own line.
     * @param aStudent The student to print the information of
     * @pre aStudent != null
     * @post [prints the student's information by calling the getters for
     * aStudent's instance variables. Prints each to their own line using println.]
     */
    public static void printStudentInformation(Student aStudent)
    {
        System.out.println("Name: " + aStudent.getName());
        System.out.println("Age: " + aStudent.getAge());
        System.out.println("Email: " + aStudent.getEmail());
    }

    public boolean equals(Object obj)
    {
        if (obj == null)
            return false;
        if (obj == this)
            return true;
        if(obj instanceof Student other)
            return this.name.equals(other.name) && this.age == other.age && this.email.equals(other.email);
        else
            return false;
    }


}
