print("Hello Python")
print("我是恩溶，一个C++学者，曾经使用过Pascal,正在写Java")
days = {'Monday', 'Tuesday', 'Wednesday',
        'Thursday', 'Friday'}
word = 'word'
sentence = "这是一个句子"
paragraph = """这是一个段落
包含了多个语句"""
'''
python的注释这么好玩！
'''
"""
原来注释可以这样写
"""
counter = 100  # 赋值整型变量
miles = 1000.0  # 浮点型
name = "John"  # 字符串
'''
print(counter)
print(miles)
print(name)
a, b, c = 1, 2, "John"
str = 'Hello World'
print(str)
print(str[0])
print(str[2:5])
print(str[2:])
print(str*2)
print(str+"TEST")
'''
tuple = ('runoob', 786, 2.23, 'john', 70.2)
tinytuple = (123, 'john')
'''
print(tuple)
print(tuple[0])
print(tuple[1:3])
print(tuple[2:])
print(tinytuple*2)
print(tuple+tinytuple)
'''
dict = {}
dict['one'] = "This is one"
dict[2] = "This is two"
tinydict = {'name': 'john', 'code': 6734,
            'dept': 'sales'}
'''
print(dict['one'])
print(dict[2])
print(tinydict)
print(tinydict.keys())
print(tinydict.values())
a = 21
b = 10
c = a + b
print("1 - c的值为：", c)
c = a - b
print("2 - c的值为", c)
c = a * b
print("3 - c的值为", c)
c = a / b
print("4 - c的值为", c)
c = a % b
print("5 - c的值为", c)
# 修改变量a,b,c
a = 2
b = 3
c = a ** b
print("6 - c的值为", c)
a = 10
b = 5
c = a // b
print("7 - c的值为", c)
'''
a = input("Enter a number :")
print("Received your input number:", a)
