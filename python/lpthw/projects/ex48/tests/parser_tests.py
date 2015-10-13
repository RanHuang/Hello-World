from nose.tools import *
from ex48 import lexicon
from ex48 import parser

def test_peek():
    word_list = lexicon.scan("bear princess")
    result = parser.peek(word_list)
    assert_equal(result, 'noun')
    assert_equal(parser.peek([]), None)

def test_match():
    result = parser.match(lexicon.scan("234 445"), 'number')
    assert_equal(result, ('number', '234'))
    result = parser.match(lexicon.scan("234 445"), 'noun')
    assert_equal(result, None)

def test_parse_verb():
    result = parser.parse_verb(lexicon.scan("at in kill bear 34587"))
    assert_equal(result, ('verb', 'kill'))
    word_list = lexicon.scan("at bear in kill bear 34587")
    # test the Exception
    #assert_raises(Exception, parser.parse_verb, word_list)
    assert_raises(parser.ParserError, parser.parse_verb, word_list)

def test_parse_object():
    result = parser.parse_object(lexicon.scan("at in bear kill 34587"))
    assert_equal(result, ('noun', 'bear'))
    result = parser.parse_object(lexicon.scan("at in east kill 34587"))
    assert_equal(result, ('direction', 'east'))

    word_list = lexicon.scan("at in kill bear 34587")
    assert_raises(parser.ParserError, parser.parse_object, word_list)

def test_parse_subject():
    result = parser.parse_subject(lexicon.scan("in of kill at princess 234 what"), ('noun', 'Player'))
    # How to test an Object, such as Sentence()
    #assert_equal(result, parser.Sentence(('noun', 'Player'), ('verb', 'kill'), ('noun', 'princess')))

def test_parse_sentence():
    result = parser.parse_sentence(lexicon.scan("in princess go at east"))
    # test the object Sentence(result)

    word_list = lexicon.scan("I kill the bear")
    assert_raises(parser.ParserError, parser.parse_sentence, word_list)
