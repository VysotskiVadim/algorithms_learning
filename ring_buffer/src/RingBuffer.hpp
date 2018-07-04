#pragma once

namespace al {

    class RingBuffer {
        private:
            int _size;
            char *_buffer;
            int _head;
            int _tail;
            int getFreeSpace();
            int getUsedSpace();
        public:
            RingBuffer();
            RingBuffer(int size);
            ~RingBuffer();
            int write(char *data, int lenght);
            int read(char *buffer, int lenght);
    };

}