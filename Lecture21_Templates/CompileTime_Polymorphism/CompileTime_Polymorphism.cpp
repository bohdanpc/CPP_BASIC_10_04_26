#include <iostream>

class FileProcessing
{
public:
    void process(const std::string& filename)
    {
        std::cout << "processing regular file";
    }
};

class NetworkProcessing
{
public:
    void process(const std::string& networkPath)
    {
        std::cout << "open socket, request connection, buffer data...\n";
    }
};

template<class T>
class DataProcessor
{
public:

    void process(const std::string& text)
    {
        m_processingUnit.process(text);
    }

private:
    T m_processingUnit;
};

int main()
{
    DataProcessor<NetworkProcessing> m_networkDataProcessor;
    m_networkDataProcessor.process("ithillel.com/hw25/lecture.pdf");

    DataProcessor<FileProcessing> m_fileDataProcessor;
    m_fileDataProcessor.process("C:\Windows\system32\boot.sys");
}
