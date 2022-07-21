from django.db import models
from django.conf import settings
from django.utils import timezone


# Create your models here.
class Todo(models.Model):
    
    #id=models.AutoField(primary_key=True) 
    task_title = models.CharField(max_length=200)
    task_description = models.TextField()
    created_date = models.DateTimeField(default=timezone.now)
    to_be_date = models.DateTimeField(blank=True, null=True)
    done_status=models.BooleanField(default=False)

    def publish(self):
        self.created_date = timezone.now()
        self.save()

    def __str__(self):
        return self.task_title