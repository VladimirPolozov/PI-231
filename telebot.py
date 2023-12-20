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

resourseKeyboard = telebot.types.ReplyKeyboardMarkup(True)
resourseKeyboard.row("C++", "Python", "Новости")
mode = 'None'
step = 0

@bot.message_handler(commands=['start'])
def startWork(message):
  mid = message.chat.id
  bot.send_message(
    mid,
    """Привет! Этот бот создан в рамках выполнения лабораторной по ИСиТ\n
       Задание №1 - Выводить ссылки на популярные сайт в сфере IT
       /showItResourses
       Задание №2 - Реагировать только на голосовые сообщения
       /onlyVoiceMessages
       Задание №3 - (режим общения)
       /conversation
       Задание №4 - удалять клавиатуру по сообщению \"Закрыть\"
       Задание №5 - работа с api
       /askApi""",
    parse_mode = "markdown"
  )

# Задание №1 - Выводить ссылки на популярные сайт в сфере IT
@bot.message_handler(commands=['showItResourses'])
def showItResourses(message):
  global mode
  mode = 'showItResourses'
  mid = message.chat.id

  if message.text == "C++":
    bot.send_message(
      mid,
      """1. https://cplusplus.com/ — онлайн-ресурс со справочной информацией по языку программирования C++\n
      2. https://en.cppreference.com/ — справочная информация и примеры использования языка программирования C++""",
      reply_markup = resourseKeyboard
    )
  elif message.text == "Python":
    bot.send_message(
      mid,
      """1. https://www.learnpython.org/ — интерактивный обучающий сайт по программированию на языке Python\n
      2. https://learn.python.ru/ — русскоязычный образовательный ресурс, предназначенный для изучения языка программирования Python\n
      3. https://docs.python.org/3/ — официальная документация по языку программирования Python версии 3, предоставляющая подробную информацию об используемых синтаксисе и структурах, а также различных модулях и библиотеках""",
      reply_markup = resourseKeyboard
    )
  elif message.text == "Новости":
    bot.send_message(
      mid,
      """1. https://tproger.ru/ — программирование с нуля, разработка приложений на разных языках, гайды, видеоуроки, книги по программированию, вакансии для программистов и ответы\n
      2. https://thecode.media/ — Код — журнал Яндекс Практикума о технологиях и программировании""",
      reply_markup = resourseKeyboard
    )

  bot.send_message(
      mid,
      "Выберите тематику IT сайта",
      parse_mode = "markdown",
      reply_markup = resourseKeyboard
    )

# Задание №2 - Реагировать только на голосовые сообщения
@bot.message_handler(commands=['onlyVoiceMessages'])
def onlyVoiceMessages(message):
  global mode
  mode = 'onlyVoiceMessages'

@bot.message_handler(content_types=['voice'])
def voiceMessage(message):
  global mode
  mid = message.chat.id
  if mode == 'onlyVoiceMessages':
    bot.send_message(
      mid,
      "Пока я не умею распозновать голосовые сообщения и отвечать на них",
    )

# Задание №3 - (режим общения)
@bot.message_handler(commands=['conversation'])
def conversation(message):
  global mode, step
  mode = 'conversation'
  mid = message.chat.id

  if step == 0:
    bot.send_message(
      mid,
      "Как тебя зовут?",
    )
  elif step == 1:
      bot.send_message(
        mid,
        "Привет, " + message.text + "! Сколько тебе лет?",
      )
  elif step == 2:
    bot.send_message(
      mid,
      "Окей, тебе " + message.text + " лет. А когда у тебя день рождения?",
    )
  elif step == 3:
    if message.text.lower() == "сегодня":
      bot.send_message(
        mid,
        "О, здорово! С Днём рождения!",
      )
    else:
      bot.send_message(
        mid,
        "Хорошо, надо запомнить",
      )
  else:
    step = 0
  step += 1

# работа с api
@bot.message_handler(commands=['askApi'])
def askApi(message):
  global mode, step
  mode = 'api'
  mid = message.chat.id

  if step == 0:
    bot.send_message(
      mid,
      "Введите число от 1 до 12"
    )
    step = 1
  elif step == 1:
    if message.text.isdigit() and int(message.text) > 0 and int(message.text) < 13:
      url = "https://reqres.in/api/users/" + message.text
      response = requests.get(url)
      data = response.json()
      bot.send_message(
        mid,
        data["data"]["email"]
      )
      step = 0
      askApi(message)
    else:
      bot.send_message(
      mid,
      "Введите число от 1 до 12"
    )


@bot.message_handler(content_types=['text'])
def sendYourMessage(message):
  global mode
  mid = message.chat.id

  if message.text == 'Закрыть':
    bot.send_message(
      mid,
      'Клавиатура закрыта',
      reply_markup=types.ReplyKeyboardRemove()
    )
  elif mode == 'None':
    startWork(message)
  elif mode == 'showItResourses':
    showItResourses(message)
  elif mode == 'onlyVoiceMessages':
    pass
  elif mode == 'conversation':
    conversation(message)
  elif mode == 'api':
    askApi(message)

bot.polling()
