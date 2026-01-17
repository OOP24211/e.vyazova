#include <gtest/gtest.h>
#include "pipeline/ProcessingPipeline.h"
#include "../errors/Errors.h"

class DummyConverter : public Converter {
public:
    int16_t process(int16_t in, uint64_t) override {
        return in + 1;
    }
};

TEST(ProcessingPipelineTest, AppliesConvertersInOrder) {
    std::vector<std::unique_ptr<Converter>> convs;
    convs.push_back(std::make_unique<DummyConverter>());
    convs.push_back(std::make_unique<DummyConverter>());

    int16_t sample = 10;
    uint64_t idx = 0;

    for (auto& c : convs)
        sample = c->process(sample, idx);

    EXPECT_EQ(sample, 12);
}
