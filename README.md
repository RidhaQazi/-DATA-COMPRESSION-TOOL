# -DATA-COMPRESSION-TOOL

COMPANY: CODETECH IT SOLUTIONS

NAME: RIDHA QAZI

INTERN ID: CODHC68

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTOSH

Data compression is a crucial technique in computing that reduces file size by eliminating redundant information while preserving essential data. For this task, I developed a C program that implements Run-Length Encoding (RLE), a simple yet effective lossless compression algorithm. The program provides a menu-driven interface that allows users to compress and decompress text files, helping reduce storage requirements and improve file transfer efficiency. To write and execute this program, I used Visual Studio Code as my coding environment due to its ease of debugging and syntax highlighting. I compiled and ran the program using the GCC compiler on a Windows OS.

The program prompts the user to enter the input file name and the output file name before selecting either compression or decompression. It reads data from the input file, processes it using the RLE algorithm, and writes the results to the specified output file. The compression function (compress()) works by scanning the file character by character, counting consecutive occurrences of the same character, and writing the count along with the character to the output file in the format count|char. For example, the sequence AAAABBBCC would be compressed into 4|A,3|B,2|C. The decompression function (decompress()) reads the compressed file, extracts the count and character pairs, and reconstructs the original data by repeating each character the specified number of times. The decompressed file should ideally match the original input file before compression.

To test the program, I used a sample input file, rle.txt, containing repetitive text patterns. After running the compression function, the output was stored in com.txt, significantly reducing the file size. I then used the decompression function to generate decom.txt, and it matched rle.txt exactly. 

## See rle.txt [rle.txt](https://github.com/user-attachments/files/18989437/rle.txt)
## See com.txt [com.txt](https://github.com/user-attachments/files/18989438/com.txt)
## See decom.txt [decom.txt](https://github.com/user-attachments/files/18989439/decom.txt) 

This RLE-based compression tool has several practical applications. It is useful in reducing file sizes for storage efficiency, especially in text-based logs, simple image encoding, and data transmission where bandwidth is limited. RLE is widely used in fax transmission, bitmap image encoding, and simple archival tools. While RLE is best suited for data with many repeating characters, it may not be effective for files with high entropy, such as encrypted text or random data.By completing this task, I gained valuable insights into file handling, character processing, and efficient encoding algorithms in C. Understanding data compression techniques like RLE provides a foundation for exploring more advanced algorithms, such as Huffman coding and Lempel-Ziv-Welch (LZW), which are used in modern compression standards like ZIP, PNG, and GIF formats. This project reinforced the importance of optimizing storage and improving data transmission while maintaining data integrity, making it a crucial concept in computing and software development.

## Output

![Image](https://github.com/user-attachments/assets/ee3fa309-24dc-4e79-82a3-7036c3133f2f)

