using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson5
{
    internal class Word
    {
        private string hebrewWord;
        private string englishWord;
        private string picturePath;

        public Word(string hebrewWord, string englishWord, string picturePath)
        {
            this.hebrewWord = hebrewWord;
            this.englishWord = englishWord;
            this.picturePath = picturePath;
        }

        public Word(Word other)
            : this(other.hebrewWord, other.englishWord, other.picturePath) { }

        public string getHebrewWord()
        {
            return hebrewWord;
        }

        public string getEnglishWord()
        {
            return englishWord;
        }

        public void setHebrewWord(string hebrewWord)
        {
            this.hebrewWord = hebrewWord;
        }

        public void setEnglishWord(string englishWord)
        {
            this.englishWord = englishWord;
        }

        public string getPicturePath()
        {
            return picturePath;
        }

        public void setPicturePath(string picturePath)
        {
            this.picturePath = picturePath;
        }

        public override string ToString()
        {
            return $"{englishWord} = {hebrewWord}";
        }
    }
}
