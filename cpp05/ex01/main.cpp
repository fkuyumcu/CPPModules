#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Test 1: Valid Bureaucrat Creation ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Default Constructor ===" << std::endl;
    try {
        Bureaucrat def;
        std::cout << def << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Highest Grade (1) ===" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Lowest Grade (150) ===" << std::endl;
    try {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Grade Too High (0) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Grade Too Low (151) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Increment Grade ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 3);
        std::cout << "Before: " << alice << std::endl;
        alice.incGrade();
        std::cout << "After increment: " << alice << std::endl;
        alice.incGrade();
        std::cout << "After increment: " << alice << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Increment Grade at Maximum (should throw) ===" << std::endl;
    try {
        Bureaucrat topGuy("TopGuy", 1);
        std::cout << "Before: " << topGuy << std::endl;
        topGuy.incGrade(); // This should throw
        std::cout << "After increment: " << topGuy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Decrement Grade ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 148);
        std::cout << "Before: " << charlie << std::endl;
        charlie.decGrade();
        std::cout << "After decrement: " << charlie << std::endl;
        charlie.decGrade();
        std::cout << "After decrement: " << charlie << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Decrement Grade at Minimum (should throw) ===" << std::endl;
    try {
        Bureaucrat lowGuy("LowGuy", 150);
        std::cout << "Before: " << lowGuy << std::endl;
        lowGuy.decGrade(); // This should throw
        std::cout << "After decrement: " << lowGuy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 11: Copy Constructor ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 12: Assignment Operator ===" << std::endl;
    try {
        Bureaucrat first("First", 10);
        Bureaucrat second("Second", 100);
        std::cout << "Before assignment:" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << std::endl;
        second = first;
        std::cout << "After assignment (second = first):" << std::endl;
        std::cout << "First: " << first << std::endl;
        std::cout << "Second: " << second << " (name stays 'Second', grade becomes 10)" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n========== FORM TESTS ==========" << std::endl;

    std::cout << "\n=== Test 13: Create Valid Form ===" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 14: Form with Grade Too High ===" << std::endl;
    try {
        Form form2("Invalid Form", 0, 50);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 15: Form with Grade Too Low ===" << std::endl;
    try {
        Form form3("Invalid Form", 50, 151);
        std::cout << form3 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 16: Successful Form Signing ===" << std::endl;
    try {
        Form form4("Contract", 100, 50);
        Bureaucrat bob("Bob", 50);
        std::cout << "Before signing: " << form4 << std::endl;
        bob.signForm(form4);
        std::cout << "After signing: " << form4 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 17: Failed Form Signing (Grade Too Low) ===" << std::endl;
    try {
        Form form5("Top Secret", 10, 5);
        Bureaucrat lowGrade("LowGrade", 100);
        std::cout << "Form: " << form5 << std::endl;
        std::cout << "Bureaucrat: " << lowGrade << std::endl;
        lowGrade.signForm(form5);
        std::cout << "After attempt: " << form5 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 18: Sign Form at Exact Grade ===" << std::endl;
    try {
        Form form6("Permission", 75, 50);
        Bureaucrat alice("Alice", 75);
        std::cout << "Form: " << form6 << std::endl;
        std::cout << "Bureaucrat: " << alice << std::endl;
        alice.signForm(form6);
        std::cout << "After signing: " << form6 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 19: Multiple Bureaucrats, Same Form ===" << std::endl;
    try {
        Form form7("Report", 100, 50);
        Bureaucrat high("HighRank", 10);
        Bureaucrat low("LowRank", 120);
        
        std::cout << "Form: " << form7 << std::endl;
        std::cout << "Attempting to sign with low-ranked bureaucrat..." << std::endl;
        low.signForm(form7);
        std::cout << "Attempting to sign with high-ranked bureaucrat..." << std::endl;
        high.signForm(form7);
        std::cout << "Final state: " << form7 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 20: Form Copy Constructor ===" << std::endl;
    try {
        Form original("Original", 42, 21);
        Bureaucrat signer("Signer", 1);
        signer.signForm(original);
        
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
