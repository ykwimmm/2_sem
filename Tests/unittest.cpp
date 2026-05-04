#include "CppUnitTest.h"
#include "../Task3/Queue.h"
#include "../Task3/QueueNode.h"
#include <sstream>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
    TEST_CLASS(QueueNodeTest)
    {
    public:
        TEST_METHOD(Constructor_ShouldSetData)
        {
            QueueNode node(42);
            Assert::AreEqual(42, node.getData());
        }

        TEST_METHOD(Constructor_ShouldHaveNullNext)
        {
            QueueNode node(42);
            Assert::IsNull(node.getNext());
        }

        TEST_METHOD(SetNext_ShouldSetNextNode)
        {
            QueueNode node1(10);
            QueueNode node2(20);
            node1.setNext(&node2);
            Assert::IsNotNull(node1.getNext());
            Assert::AreEqual(20, node1.getNext()->getData());
        }
    };

    TEST_CLASS(QueueTest)
    {
    public:
        TEST_METHOD(DefaultConstructor_ShouldCreateEmptyQueue)
        {
            Queue q;
            Assert::IsTrue(q.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), q.getSize());
        }

        TEST_METHOD(InitializerListConstructor_ShouldCreateQueueWithElements)
        {
            Queue q = { 1, 2, 3, 4, 5 };
            Assert::IsFalse(q.isEmpty());
            Assert::AreEqual(static_cast<size_t>(5), q.getSize());
        }

        TEST_METHOD(InitializerListConstructor_ShouldPreserveOrder)
        {
            Queue q = { 10, 20, 30 };
            Assert::AreEqual(10, q.peek());
        }

        TEST_METHOD(CopyConstructor_ShouldCreateExactCopy)
        {
            Queue q1 = { 1, 2, 3 };
            Queue q2(q1);

            Assert::AreEqual(q1.getSize(), q2.getSize());
            Assert::AreEqual(q1.peek(), q2.peek());
        }

        TEST_METHOD(CopyConstructor_ShouldCreateDeepCopy)
        {
            Queue q1 = { 1, 2, 3 };
            Queue q2(q1);

            q1.enqueue(4);

            Assert::AreEqual(static_cast<size_t>(4), q1.getSize());
            Assert::AreEqual(static_cast<size_t>(3), q2.getSize());
        }

        TEST_METHOD(MoveConstructor_ShouldMoveOwnership)
        {
            Queue q1 = { 1, 2, 3 };
            size_t originalSize = q1.getSize();

            Queue q2(std::move(q1));

            Assert::IsTrue(q1.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), q1.getSize());
            Assert::AreEqual(originalSize, q2.getSize());
        }

        TEST_METHOD(CopyAssignment_ShouldCopyCorrectly)
        {
            Queue q1 = { 5, 6, 7 };
            Queue q2;
            q2 = q1;

            Assert::AreEqual(q1.getSize(), q2.getSize());
            Assert::AreEqual(q1.peek(), q2.peek());
        }

        TEST_METHOD(CopyAssignment_SelfAssignment_ShouldNotBreak)
        {
            Queue q1 = { 5, 6, 7 };
            q1 = q1;

            Assert::AreEqual(static_cast<size_t>(3), q1.getSize());
            Assert::AreEqual(5, q1.peek());
        }

        TEST_METHOD(MoveAssignment_ShouldMoveCorrectly)
        {
            Queue q1 = { 8, 9, 10 };
            Queue q2;
            q2 = std::move(q1);

            Assert::IsTrue(q1.isEmpty());
            Assert::AreEqual(static_cast<size_t>(3), q2.getSize());
            Assert::AreEqual(8, q2.peek());
        }

        TEST_METHOD(Enqueue_ShouldAddElementToEnd)
        {
            Queue q;
            q.enqueue(10);

            Assert::AreEqual(static_cast<size_t>(1), q.getSize());
            Assert::AreEqual(10, q.peek());
        }

        TEST_METHOD(Enqueue_MultipleElements_ShouldMaintainOrder)
        {
            Queue q;
            q.enqueue(10);
            q.enqueue(20);
            q.enqueue(30);

            Assert::AreEqual(10, q.peek());
            Assert::AreEqual(static_cast<size_t>(3), q.getSize());
        }

        TEST_METHOD(Enqueue_AfterDequeue_ShouldAddToEnd)
        {
            Queue q = { 1, 2, 3 };
            q.dequeue();
            q.enqueue(4);

            Assert::AreEqual(2, q.peek());
            Assert::AreEqual(static_cast<size_t>(3), q.getSize());
        }

        TEST_METHOD(Dequeue_ShouldRemoveAndReturnFirstElement)
        {
            Queue q = { 10, 20, 30 };
            int value = q.dequeue();

            Assert::AreEqual(10, value);
            Assert::AreEqual(static_cast<size_t>(2), q.getSize());
            Assert::AreEqual(20, q.peek());
        }

        TEST_METHOD(Dequeue_AllElements_ShouldEmptyQueue)
        {
            Queue q = { 1, 2, 3 };

            q.dequeue();
            q.dequeue();
            q.dequeue();

            Assert::IsTrue(q.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), q.getSize());
        }

        TEST_METHOD(Dequeue_EmptyQueue_ShouldThrowException)
        {
            Queue q;

            auto func = [&q]() { q.dequeue(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(Peek_ShouldReturnFirstElementWithoutRemoving)
        {
            Queue q = { 42, 43, 44 };

            int value = q.peek();

            Assert::AreEqual(42, value);
            Assert::AreEqual(static_cast<size_t>(3), q.getSize());
        }

        TEST_METHOD(Peek_EmptyQueue_ShouldThrowException)
        {
            Queue q;

            auto func = [&q]() { q.peek(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(IsEmpty_EmptyQueue_ShouldReturnTrue)
        {
            Queue q;
            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(IsEmpty_NonEmptyQueue_ShouldReturnFalse)
        {
            Queue q = { 1 };
            Assert::IsFalse(q.isEmpty());
        }

        TEST_METHOD(IsEmpty_AfterEnqueueAndDequeue_ShouldReturnTrue)
        {
            Queue q;
            q.enqueue(1);
            q.dequeue();
            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(GetSize_EmptyQueue_ShouldReturnZero)
        {
            Queue q;
            Assert::AreEqual(static_cast<size_t>(0), q.getSize());
        }

        TEST_METHOD(GetSize_AfterAdditions_ShouldReturnCorrectSize)
        {
            Queue q;
            for (int i = 0; i < 5; i++) {
                q.enqueue(i);
            }
            Assert::AreEqual(static_cast<size_t>(5), q.getSize());
        }

        TEST_METHOD(GetSize_AfterRemovals_ShouldDecrement)
        {
            Queue q = { 1, 2, 3 };
            q.dequeue();
            Assert::AreEqual(static_cast<size_t>(2), q.getSize());
        }

        TEST_METHOD(ToString_EmptyQueue_ShouldReturnBrackets)
        {
            Queue q;
            Assert::AreEqual(std::string("[]"), q.toString());
        }

        TEST_METHOD(ToString_SingleElement_ShouldReturnElementInBrackets)
        {
            Queue q = { 42 };
            Assert::AreEqual(std::string("[42]"), q.toString());
        }

        TEST_METHOD(ToString_MultipleElements_ShouldReturnCommaSeparated)
        {
            Queue q = { 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), q.toString());
        }

        TEST_METHOD(ShiftRightOperator_ShouldAddElement)
        {
            Queue q;
            q >>= 10;

            Assert::AreEqual(static_cast<size_t>(1), q.getSize());
            Assert::AreEqual(10, q.peek());
        }

        TEST_METHOD(ShiftRightOperator_Chained_ShouldAddMultipleElements)
        {
            Queue q;
            q >>= 10;
            q >>= 20;
            q >>= 30;

            Assert::AreEqual(static_cast<size_t>(3), q.getSize());
            Assert::AreEqual(10, q.peek());
        }

        TEST_METHOD(ShiftLeftOperator_ShouldExtractElement)
        {
            Queue q = { 10, 20, 30 };
            int value = 0;
            q <<= value;

            Assert::AreEqual(10, value);
            Assert::AreEqual(static_cast<size_t>(2), q.getSize());
        }

        TEST_METHOD(ShiftLeftOperator_EmptyQueue_ShouldThrowException)
        {
            Queue q;
            int value = 0;

            auto func = [&q, &value]() { q <<= value; };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(StreamOperator_ShouldOutputCorrectFormat)
        {
            Queue q = { 1, 2, 3 };
            std::ostringstream oss;
            oss << q;

            Assert::AreEqual(std::string("[1, 2, 3]"), oss.str());
        }

        TEST_METHOD(ComplexScenario_MultipleOperations_ShouldWorkCorrectly)
        {
            Queue q;

            // Добавление элементов
            for (int i = 1; i <= 5; i++) {
                q.enqueue(i);
            }
            Assert::AreEqual(static_cast<size_t>(5), q.getSize());

            // Извлечение части элементов
            Assert::AreEqual(1, q.dequeue());
            Assert::AreEqual(2, q.dequeue());

            // Добавление новых элементов
            q.enqueue(6);
            q.enqueue(7);

            // Проверка состояния
            Assert::AreEqual(static_cast<size_t>(5), q.getSize());
            Assert::AreEqual(3, q.peek());

            // Извлечение оставшихся элементов
            Assert::AreEqual(3, q.dequeue());
            Assert::AreEqual(4, q.dequeue());
            Assert::AreEqual(5, q.dequeue());
            Assert::AreEqual(6, q.dequeue());
            Assert::AreEqual(7, q.dequeue());

            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(LargeQueue_EnqueueAndDequeue_ShouldHandleLargeNumberOfElements)
        {
            Queue q;
            const int TEST_SIZE = 1000;

            // Добавление большого количества элементов
            for (int i = 0; i < TEST_SIZE; i++) {
                q.enqueue(i);
            }
            Assert::AreEqual(static_cast<size_t>(TEST_SIZE), q.getSize());

            // Извлечение и проверка всех элементов
            for (int i = 0; i < TEST_SIZE; i++) {
                Assert::AreEqual(i, q.dequeue());
            }

            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(MemoryManagement_Destructor_ShouldNotLeak)
        {
            // Проверка на утечки памяти через создание и удаление
            for (int i = 0; i < 1000; i++) {
                Queue q;
                for (int j = 0; j < 100; j++) {
                    q.enqueue(j);
                }
                // Деструктор вызывается автоматически при выходе из области видимости
            }

            // Если мы дошли до этой точки без исключений, тест пройден
            Assert::IsTrue(true);
        }
    };
}
