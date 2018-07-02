#pragma once

namespace al {

    class RingBuffer {
        private:
            int _size;
            char *_buffer; 
        public:
            RingBuffer();
            RingBuffer(int size);
            ~RingBuffer();
    };

}