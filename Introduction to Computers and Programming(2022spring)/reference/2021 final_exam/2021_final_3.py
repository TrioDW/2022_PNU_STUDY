# [3] Dict를 이용한 최단 출현 단어 찾기
# 다음 영문 문자열에서 가장 많이 나타난 단어를 찾는 프로그램을 Dictionary를 이용해서 해결하시오.
# 단 Collection을 사용해서는 안 된다. 반드시 1개의 Dictionary word_freq={ } 만을 사용해야 한다.
# 이 과정의 처리 조건은 다음과 같다. 단 실제 평가할 때에는 다른 다양한 문자열로 검사하고 채점한다.

# 1) 대소문자는 구별하지 않는다.
# 2) 단어는 공백과 공백으로 분리된 어절로 구분하지만 각 구분된 어절의 끝에 있는 콤마나 물음표,
#    느낌표 등의 문자는 제외한다.
# 3) 즉 "worked"와 "worked.", "Worked", "WORKed?"는 모든 같은 단어로 처리해야 한다.
# 4) 단어의 길이가 2 이하인 것은 제외한다. 예를 들어 “to”, “of”, “a”, “an” 등


Text = '''
Algorithms and technology have so far helped listeners to more of
the same music. Now, UiO researchers are people working on new
technology that can get people interested in a greater musical
variety. Chords, beat, timbre, people, people, rhythm and harmony.
All these elements of music contribute to make it sound the way it
does. But have you thought about why you like particular kinds of
music? people Music is a people magical thing, when you think about
it. When you listen, you feel many emotions. You understand that it
is a kind of language, but you cannot see what is happening. For
most people, it is a mystery. So says Olivier Lartillot, researcher
at RITMO Center for Interdisciplinary people Studies in Rhythm, Time
and Motion. He is developing new digital tools that he hopes will
make the magic of music available to everyone. First on his list is
Norwegian folk music. "Folk music is so rich, and a treasure for
Norwegian culture." Still, not many people listen to it People. If we
create a tool that can help people understand music, folk music may
have a renaissance in Norway, says Lartillot people. People? Yes
peoples?
'''


Text = Text.lower()
Text = Text.replace('?', ' ')
Text = Text.replace('!', ' ')
Text = Text.replace('"', ' ')
Text = Text.replace('.', ' ')
Text = Text.replace(',', ' ')

Text = Text.split()

new_text = []

for w in range(len(Text)):
    if len(Text[w]) < 3:
        continue

    else:
        new_text.append(Text[w])

dictionary = dict()

for i in new_text:
    try:
        dictionary[i] = dictionary[i] + 1
    except:
        dictionary[i] = 1

print(dictionary)

ans = sorted(dictionary.items(), key=lambda x: x[1])

print(ans[-1][0])
