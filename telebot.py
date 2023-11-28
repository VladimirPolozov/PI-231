import telebot
from telebot import types
import requests


sample = {
  'content_type': 'text',
  'id': 53,
  'message_id': 53,
  'from_user': {
    'id': 1052415116,
    'is_bot': False,
    'first_name': 'Володя',
    'username': 'IamVoIodya',
    'last_name': None,
    'language_code': 'ru',
    'can_join_groups': None,
    'can_read_all_group_messages': None,
    'supports_inline_queries': None
    },
    'date': 1701185357,
    'chat': {
      'id': 1052415116,
      'type': 'private',
      'title': None,
      'username': 'IamVoIodya',
      'first_name': 'Володя',
      'last_name': None,
      'photo': None,
      'bio': None,
      'has_private_forwards': None,
      'description': None,
      'invite_link': None,
      'pinned_message': None,
      'permissions': None,
      'slow_mode_delay': None,
      'message_auto_delete_time': None,
      'has_protected_content': None,
      'sticker_set_name': None,
      'can_set_sticker_set': None,
      'linked_chat_id': None,
      'location': None
      },
      'sender_chat': None,
      'forward_from': None,
      'forward_from_chat': None,
      'forward_from_message_id': None,
      'forward_signature': None,
      'forward_sender_name': None, 
      'forward_date': None,
      'is_automatic_forward': None,
      'reply_to_message': None,
      'via_bot': None,
      'edit_date': None,
      'has_protected_content': None,
      'media_group_id': None,
      'author_signature': None,
      'text': 'В',
      'entities': None,
      'caption_entities': None,
      'audio': None,
      'document': None,
      'photo': None,
      'sticker': None,
      'video': None,
      'video_note': None,
      'voice': None,
      'caption': None,
      'contact': None,
      'location': None,
      'venue': None,
      'animation': None,
      'dice': None,
      'new_chat_member': None,
      'new_chat_members': None,
      'left_chat_member': None,
      'new_chat_title': None,
      'new_chat_photo': None,
      'delete_chat_photo': None,
      'group_chat_created': None,
      'supergroup_chat_created': None,
      'channel_chat_created': None,
      'migrate_to_chat_id': None,
      'migrate_from_chat_id': None,
      'pinned_message': None,
      'invoice': None,
      'successful_payment': None,
      'connected_website': None,
      'reply_markup': None,
      'json': {'message_id': 53, 'from': {'id': 1052415116, 'is_bot': False, 'first_name': 'Володя', 'username': 'IamVoIodya', 'language_code': 'ru'}, 'chat': {'id': 1052415116, 'first_name': 'Володя', 'username': 'IamVoIodya', 'type': 'private'}, 'date': 1701185357, 'text': 'В'}}

TOKEN = "6699201868:AAFwiT3AOT36X0oNHL83tIACsAd5ZZuPKDU"
bot = telebot.TeleBot(TOKEN)

conversation = 0
resourseKeyboard = telebot.types.ReplyKeyboardMarkup(True)
resourseKeyboard.row("C++", "Python", "Новости")

def askWikipedia(question, mid):
  url = "https://ru.wikipedia.org/w/api.php"
  params = {
    "action": "query",
    "prop": "extracts",
    "format": "json",
    "exintro": "",
    "explainrefer": "",
    "titles": question
  }
  response = requests.get(url, params=params)
  data = response.json()
  
  try:
    if data["query"]["pages"]['-1']:
      bot.send_message(
        mid,
        "Не найдено страниц на Википедии по данному запросу",
        parse_mode = "markdown"
      )
  except KeyError:
    for article in data['query']['pages']:
      bot.send_message(
        mid,
        data['query']['pages'][article]['extract'],
        parse_mode = "markdown"
      )
      break
  except Exception:
    bot.send_message(
      mid,
      "Ошибка. Не удалось обработать запрос",
    )

@bot.message_handler(commands=['start'])
def startWork(message):
  mid = message.chat.id
  bot.send_message(
    mid,
    "Привет! Этот бот создан в рамках выполнения лабораторной по ИСиТ\n\nЗадание №1 - Вывод ссылок по IT тематике\n/showItResourses\nЗадание №3 (режим общения)\n/conversation",
    parse_mode = "markdown",
    reply_markup = types.ReplyKeyboardRemove()
  )

@bot.message_handler(commands=['showItResourses'])
def showItResourses(message):
  mid = message.chat.id
  bot.send_message(
    mid,
    "Выберите тематику",
    parse_mode = "markdown",
    reply_markup = resourseKeyboard
  )

@bot.message_handler(commands=['conversation'])
def showItResourses(message):
  global conversation
  mid = message.chat.id
  conversation += 1
  bot.send_message(
    mid,
    "Как тебя зовут?",
    parse_mode = "markdown",
    reply_markup = types.ReplyKeyboardRemove()
  )

@bot.message_handler(content_types=['text'])
def sendYourMessage(message):
  global conversation
  mid = message.chat.id
  if conversation:
    if conversation == 1:
      conversation += 1
      bot.send_message(
        mid,
        "Привет, " + message.text + "! Сколько тебе лет?",
        parse_mode = "markdown",
      )
    elif conversation == 2:
      conversation += 1
      bot.send_message(
        mid,
        "Окей, тебе " + message.text + " лет. А когда у тебя день рождения?",
        parse_mode = "markdown",
      )
    elif conversation == 3:
      conversation += 1
      if message.text.lower() == "сегодня":
        bot.send_message(
          mid,
          "О, здорово! С Днём рождения!",
          parse_mode = "markdown",
        )
      else:
        bot.send_message(
          mid,
          "Хорошо, надо запомнить",
          parse_mode = "markdown",
        )
    else:
      conversation = 0

  if message.text == "C++":
    bot.send_message(
      mid,
      "1. https://cplusplus.com/ — онлайн-ресурс со справочной информацией по языку программирования C++\n2. https://en.cppreference.com/ — справочная информация и примеры использования языка программирования C++",
      parse_mode = "markdown",
      reply_markup = resourseKeyboard
    )
  elif message.text == "Python":
    bot.send_message(
      mid,
      "1. https://www.learnpython.org/ — интерактивный обучающий сайт по программированию на языке Python\n2. https://learn.python.ru/ — русскоязычный образовательный ресурс, предназначенный для изучения языка программирования Python\n3. https://docs.python.org/3/ — официальная документация по языку программирования Python версии 3, предоставляющая подробную информацию об используемых синтаксисе и структурах, а также различных модулях и библиотеках",
      parse_mode = "markdown",
      reply_markup = resourseKeyboard
    )
  elif message.text == "Новости":
    bot.send_message(
      mid,
      "1. https://tproger.ru/ — программирование с нуля, разработка приложений на разных языках, гайды, видеоуроки, книги по программированию, вакансии для программистов и ответы\n2. https://thecode.media/ — Код — журнал Яндекс Практикума о технологиях и программировании",
      parse_mode = "markdown",
      reply_markup = resourseKeyboard
    )
  else:
    askWikipedia(message.text, mid)

@bot.message_handler(content_types=['voice'])
def sendYourMessage(message):
  mid = message.chat.id
  bot.send_message(
    mid,
    "Пока я не умею распозновать голосовые сообщения и отвечать на них",
    parse_mode = "markdown"
  )

bot.polling()
