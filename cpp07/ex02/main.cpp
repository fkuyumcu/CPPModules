#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "=== Array Template Kullanım Örnekleri ===" << std::endl << std::endl;

    try {
        // 1. TEMEL KULLANIM
        std::cout << "1. Array oluşturma ve kullanma:" << std::endl;
        Array<int> numbers(5);
        
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = (i + 1) * 10;   
        }
        
        std::cout << "Numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << " (size: " << numbers.size() << ")" << std::endl << std::endl;
        
        // 2. FARKLI TİPLERLE KULLANIM
        std::cout << "2. Farklı tiplerle kullanım:" << std::endl;
        
        // String array
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "World";  
        words[2] = "C++";
        std::cout << "String array: ";
        for (unsigned int i = 0; i < words.size(); ++i) {
            std::cout << words[i] << " ";
        }
        std::cout << std::endl;
        
        // Double array
        Array<double> prices(4);
        prices[0] = 19.99;
        prices[1] = 49.99;
        prices[2] = 99.99;
        prices[3] = 199.99;
        std::cout << "Price array: ";
        for (unsigned int i = 0; i < prices.size(); ++i) {
            std::cout << prices[i] << "$ ";
        }
        std::cout << std::endl << std::endl;
        
        std::cout << "3. Array kopyalama:" << std::endl;
        Array<int> original(3);
        original[0] = 100;
        original[1] = 200;
        original[2] = 300;
        
        Array<int> copied(original);           // Copy constructor
        Array<int> assigned = original;        // Assignment operator
        
        std::cout << "Original: ";
        for (unsigned int i = 0; i < original.size(); ++i) {
            std::cout << original[i] << " ";
        }
        std::cout << std::endl;
        
        // Deep copy test
        original[0] = 999;
        std::cout << "Original değişti: " << original[0] << ", Copied hala: " << copied[0] << std::endl << std::endl;
        
        // 4. BOŞ ARRAY
        std::cout << "4. Boş array:" << std::endl;
        Array<int> empty;
        std::cout << "Boş array boyutu: " << empty.size() << std::endl << std::endl;
        
        // 5. EXCEPTION HANDLİNG 
        std::cout << "5. Hatalı erişim testi:" << std::endl;
        try {
            std::cout << "numbers[2] = " << numbers[2] << " (geçerli)" << std::endl;
            std::cout << "numbers[10] erişimi: ";
            std::cout << numbers[10] << std::endl;  // Exception fırlatacak
        } catch (const std::exception& e) {
            std::cout << "Hata yakalandı: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Genel hata: " << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl << "✅ Array template başarıyla kullanıldı!" << std::endl;
    return 0;
}